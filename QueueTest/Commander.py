import pygame
import time
from pygame.locals import *
import paho.mqtt.client as mqtt

pygame.init()
joysticks = []

LEFT_STICK_X = 0;
LEFT_STICK_Y = 1;
RUDDER_X = 2;
RUDDER_Y = 5;
RIGHT_STICK_X = 3;
RIGHT_STICK_Y = 4;
TOPIC = "holly/movement"
BROKER_ADDRESS = "192.168.0.35"
CLIENT_NAME = "Client1"

def initialise_joysticks():
    for i in range(pygame.joystick.get_count()):
        joysticks.append(pygame.joystick.Joystick(i))
        joysticks[-1].init()

def connect_mqqt_client(broker_address, client_name):
    client = mqtt.Client(client_name)
    client.connect(broker_address)
    client.publish(TOPIC, "Joystick ready")

connect_mqqt_client(BROKER_ADDRESS, CLIENT_NAME)
initialise_joysticks()
