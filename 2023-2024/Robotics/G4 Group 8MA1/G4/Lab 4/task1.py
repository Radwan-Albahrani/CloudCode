#!/usr/bin/env pybricks-micropython
from pybricks.ev3devices import *
from pybricks import ev3brick as brick
from pybricks.ev3devices import Motor, UltrasonicSensor, ColorSensor
from pybricks.tools import wait
from pybricks.robotics import DriveBase
from pybricks.parameters import (
    Port,
    Button,
    Color,
    ImageFile,
    SoundFile,
    Stop,
    Direction,
    Align,
)

# Setting up the drivebase
left_motor = Motor(Port.B)
right_motor = Motor(Port.C)
wheel_diameter = 56
axle_track = 114
robot = DriveBase(left_motor, right_motor, wheel_diameter, axle_track)

# Setting up the color sensor
color_sensor = ColorSensor(Port.S3)


# As long as the color sensor detects black, the robot will move forward
# Black is from 0 to 20 pct


def follow_line():
    counterLeft = 0
    counterRight = 0
    counterStop = 0
    flag = 0
    while True:
        if check_color(True):
            robot.drive(100, 0)
            counterStop = 0
            counterLeft = 0
            counterRight = 0
            flag = 0
        else:
            flag = 1
        if flag == 1:
            if counterRight < 100 and check_color():
                robot.drive(50, counterRight + 30)
                counterRight += 1
                if check_color(True):
                    flag = 0
                    continue
            elif counterLeft < 100 and check_color():
                robot.drive(50, -counterLeft - 30)
                counterLeft += 1
                if check_color(True):
                    flag = 0
                    continue
            counterStop += 1
        if counterStop > 2000:
            robot.stop()
            counterStop = 0
            counterLeft = 0
            counterRight = 0
            break
        wait(0.1)


def check_color(reflection=False):
    return (
        color_sensor.reflection() > 30
        if not reflection
        else color_sensor.reflection() < 30
    )


if __name__ == "__main__":
    follow_line()
