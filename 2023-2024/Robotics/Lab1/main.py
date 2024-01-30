#!/usr/bin/env pybricks-micropython
from pybricks.hubs import EV3Brick
from pybricks.ev3devices import Motor
from pybricks.parameters import Port
from pybricks.robotics import DriveBase

# Create your objects here

# Initialize the EV3 Brick.
ev3 = EV3Brick()

# Initialize a motor at port B.
left_wheel = Motor(Port.B)
right_wheel = Motor(Port.C)

# Connect Wheels
robot = DriveBase(left_wheel, right_wheel, 56, 114)

# Play a sound.
ev3.speaker.beep()

# Run the motor up to 500 degrees per second. To a target angle of 90 degrees.
robot.straight(500)

# Play another beep sound.
# ev3.speaker.beep(frequency=1000, duration=5000)
