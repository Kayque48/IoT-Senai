from flask import Flask, render_template, jsonify
import serial
import time
import threading

app = Flask(__name__)

# Variáveis globais para controle do estado
sensor_presence = False
last_sensor_read = None

try:
    arduino = serial.Serial('COM3', 9600, timeout=1)
    time.sleep(2)
except serial.SerialException as e:
    print(f"Erro ao conectar com Arduino: {e}")
    arduino = None

def read_arduino():
    global sensor_presence, last_sensor_read
    while True:
        if arduino:
            try:
                data = arduino.readline().decode().strip()
                if data.startswith('SENSOR:'):
                    sensor_value = int(data.split(':')[1])
                    sensor_presence = (sensor_value == 1)
                    last_sensor_read = time.time()
            except Exception as e:
                print(f"Erro na leitura do Arduino: {e}")
        time.sleep(0.1)

# Inicia thread de leitura do Arduino
arduino_thread = threading.Thread(target=read_arduino, daemon=True)
arduino_thread.start()

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/sensor-status')
def sensor_status():
    global sensor_presence, last_sensor_read
    return jsonify({
        'presence': sensor_presence,
        'last_read': last_sensor_read,
        'status': 'online' if arduino else 'offline'
    })

@app.route('/control/<led_num>/<action>')
def control(led_num, action):
    if arduino:
        cmd = 'ON' if action.lower() == 'on' else 'OFF'
        try:
            arduino.write((cmd + '\n').encode())
            time.sleep(0.1)
            resposta = arduino.readline().decode().strip()
            return resposta or f"Comando enviado: {cmd}"
        except Exception as e:
            return f"Erro ao enviar comando: {e}"
    else:
        return "Arduino não conectado."

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader=False)