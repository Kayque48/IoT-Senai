from flask import Flask, render_template
import serial
import time

try:
    arduino = serial.Serial('COM3', 9600, timeout=1)
    time.sleep(2)
except serial.SerialException as e:
    print(f"Erro ao conectar com Arduino: {e}")
    arduino = None

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

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