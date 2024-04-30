#!/usr/bin/env pybricks-micropython

from pybricks.ev3devices import (
    Motor,
    TouchSensor,
    ColorSensor,
    InfraredSensor,
    UltrasonicSensor,
    GyroSensor,
)
import time
from pybricks.hubs import EV3Brick
from pybricks.robotics import DriveBase
from pybricks.parameters import (
    Port,
    Stop,
    Direction,
    Button,
    Color,
    SoundFile,
    ImageFile,
    Align,
)
from pybricks.tools import print, wait, StopWatch

import struct

MAX_SPEED = 120
MAX_CANNON_SPEED = 10000
MAX_RESET_SPEED = 120
MAX_ROTATION_RESET = -120

# Create your objects here.
left_motor = Motor(Port.A)
right_motor = Motor(Port.D)
ultrasonic = UltrasonicSensor(Port.S2)
cannon = Motor(Port.C)

cannon.run_until_stalled(MAX_CANNON_SPEED)
cannon.reset_angle(0)
cannon.run_angle(MAX_RESET_SPEED, MAX_ROTATION_RESET)

left_speed = 0
right_speed = 0

# Locat the event file you want to react to, on my setup the PS4 controller button events
# are located in /dev/input/event4
infile_path = "/dev/input/event4"
in_file = open(infile_path, "rb")

# Define the format the event data will be read
# See https://docs.python.org/3/library/struct.html#format-characters for more details
FORMAT = "llHHi"
EVENT_SIZE = struct.calcsize(FORMAT)
event = in_file.read(EVENT_SIZE)


# A helper function for converting stick values (0 to 255) to more usable numbers (-100 to 100)
def scale(val, src, dst):
    return (float(val - src[0]) / (src[1] - src[0])) * (dst[1] - dst[0]) + dst[0]


# Create a loop to react to events
while event:

    # Place event data into variables
    (tv_sec, tv_usec, ev_type, code, value) = struct.unpack(FORMAT, event)

    if ultrasonic.distance() < 100:
        left_motor.dc(-MAX_SPEED / 2)
        right_motor.dc(-MAX_SPEED / 2)
        left_speed = 0
        right_speed = 0
        time.sleep(1)
        # Set motor speed
        left_motor.dc(left_speed)
        right_motor.dc(right_speed)
        # Read the next event
        event = in_file.read(EVENT_SIZE)
        continue

    # If a button was pressed or released
    if ev_type == 1:
        if code == 310 and value == 0:
            cannon.dc(MAX_CANNON_SPEED)
            time.sleep(0.5)
            cannon.reset_angle(0)
            cannon.run_angle(MAX_RESET_SPEED, MAX_ROTATION_RESET)

    elif ev_type == 3:  # Stick was moved

        # React to the left stick
        if code == 1:
            left_speed = scale(value, (0, 255), (MAX_SPEED, -MAX_SPEED))

        # React to the right stick
        if code == 4:
            right_speed = scale(value, (0, 255), (MAX_SPEED, -MAX_SPEED))

    # Set motor speed
    left_motor.dc(left_speed)
    right_motor.dc(right_speed)

    # Read the next event
    event = in_file.read(EVENT_SIZE)



in_file.close()
