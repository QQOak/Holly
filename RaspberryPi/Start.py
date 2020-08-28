import CommandBuilder
from flask import Flask, request, send_from_directory, jsonify

app = Flask(__name__, static_url_path='')


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
    
    serialCommand = getXYW(content)
    writeToSerialPort(serialCommand)
    return jsonify(serialCommand)
  

def writeToSerialPort(values):
    print('Writing to Serial Port')
    print(values)
    
    
def getXYW(content):
    translateValues = content['translateValues']
    rotateValues = content['rotateValues']
        
    return {
        't' : translateValues['x'],
        'm' : translateValues['y'],
        'w' : rotateValues['x'],
    }
    


if __name__ == "__main__":
    app.run()
