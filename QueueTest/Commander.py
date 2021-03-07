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

LAST_X = 0
LAST_Y = 0
LAST_R = 0
change_made = False
DIFFERENCE_NEEDED = 0

def initialise_joysticks():
    for i in range(pygame.joystick.get_count()):
        joysticks.append(pygame.joystick.Joystick(i))
        joysticks[-1].init()

def connect_mqqt_client(broker_address, client_name):
    global client
    client = mqtt.Client(client_name)
    client.connect(broker_address)
    client.publish(TOPIC, "Joystick ready")
    
def check_change(last_value, new_value, change_made):
    rounded_value = round(new_value, 4)
    if last_value != rounded_value:
        return rounded_value, True
    return last_value, change_made
    
def handle_events():
    global LAST_X
    global LAST_Y
    global LAST_R
    global change_made
    for event in pygame.event.get():            
        if event.type == JOYAXISMOTION:
            if event.axis == LEFT_STICK_X:
                LAST_X, change_made = check_change(LAST_X, event.value, change_made)
                
            if event.axis == LEFT_STICK_Y:
                LAST_Y, change_made = check_change(LAST_Y, event.value, change_made)
                
            if event.axis == RIGHT_STICK_X:
                LAST_R, change_made = check_change(LAST_R, event.value, change_made)

connect_mqqt_client(BROKER_ADDRESS, CLIENT_NAME)
initialise_joysticks()


print("Starting")
while True:
    
    try:
        
            
        change_made = False
        handle_events()
        if change_made:
            client.publish(TOPIC, "x:{0},y:{1},z:{2}".format(LAST_X, LAST_Y, LAST_R))
            change_made = False


    except KeyboardInterrupt:
        client.disconnect()
        print("Ended")
        break
