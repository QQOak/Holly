import CommandBuilder
from flask import Flask, request, send_from_directory
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
    

@app.route('/control/<x>/<y>', methods = ['GET', 'POST'])
def control(x, y):
    return '200'


if __name__ == "__main__":
    app.run()
