import CommandBuilder
from flask import Flask, request, send_from_directory, jsonify
import serial
import json

app = Flask(__name__, static_url_path='')
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=2)

@app.before_first_request
def initialise():
    pass
    

@app.route('/')
def hello_world():
    return send_from_directory('static', 'control.html')

@app.route("/scripts/<path:filename>")
def send_js(filename):
    return send_from_directory('scripts', filename)
    
@app.route('/static/<path:filename>')
def send_static(filename):
    return send_from_directory('static', filename)
    

@app.route('/control', methods = ['GET', 'POST'])
def control():
    content = request.json
    
    xyw = get_xyw_from_gamepad_json(content)
    tmw = get_tmw_from_xyw(xyw)    
    
    serialCommand = get_serial_command_from_tmw(tmw)    
    write_to_serial(serialCommand)
    
    return jsonify(serialCommand)
  
    
def get_xyw_from_gamepad_json(content):
    translateValues = content['translateValues']
    rotateValues = content['rotateValues']
    
    return {
        'x' : translateValues['x'],
        'y' : translateValues['y'],
        'w' : rotateValues['x']
    }
    
def get_tmw_from_xyw(xyw):
    return {
        't' : xyw['x'],
        'm' : xyw['y'],
        'w' : xyw['w']
    }
    
def get_serial_command_from_tmw(tmw):
    return json.dumps(tmw)
    
    

def write_to_serial(message):
    ser.write(message.encode())
    print('Writing to Serial Port')
    print(message)
    


if __name__ == "__main__":
    app.run()
