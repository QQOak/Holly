import pygame
import time
from pygame.locals import *

pygame.init()
joysticks = []

LEFT_STICK_X = 0;
LEFT_STICK_Y = 1;
RUDDER_X = 2;
RUDDER_Y = 5;
RIGHT_STICK_X = 3;
RIGHT_STICK_Y = 4;

for i in range(pygame.joystick.get_count()):
    joysticks.append(pygame.joystick.Joystick(i))
    joysticks[-1].init()
    
def handle_events():
    for event in pygame.event.get():
        if event.type == JOYBUTTONDOWN or event.type == JOYBUTTONUP:
            print(event)
            
        #if event.type == JOYHATMOTION:
        #    print(event)
            
        if event.type == JOYAXISMOTION:
            if event.axis == LEFT_STICK_X:
                print(event)
                
        if event.type == JOYAXISMOTION:
            if event.axis == LEFT_STICK_Y:
                print(event)
                
        if event.type == JOYAXISMOTION:
            if event.axis == RUDDER_X:
                print(event)
                
        if event.type == JOYAXISMOTION:
            if event.axis == RUDDER_Y:
                print(event)
        
        if event.type == JOYAXISMOTION:
            if event.axis == RIGHT_STICK_X:
                print(event)
                
        if event.type == JOYAXISMOTION:
            if event.axis == RIGHT_STICK_Y:
                print(event)


while(True):
    time.sleep(1)
    #print(len(pygame.event.get()))
    handle_events()
    
