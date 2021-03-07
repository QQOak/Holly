import paho.mqtt.client as mqtt

broker_address = "192.168.0.35"
client_name = "Client1"

client = mqtt.Client(client_name)
client.connect(broker_address)
client.publish("testTopic", "Hello World")


