#!/usr/bin/env pybricks-micropython
from pybricks import ev3brick as brick
from pybricks.ev3devices import *
from pybricks import ev3brick as brick
from pybricks.ev3devices import Motor, UltrasonicSensor
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

brick.display.text("Group 4", (50, 50))
brick.sound.file(SoundFile.ONE, 1000)
brick.sound.file(SoundFile.TWO, 1000)
brick.sound.file(SoundFile.THREE, 1000)

while True:
    if Button.LEFT in brick.buttons():
        brick.light(None)

    elif Button.RIGHT in brick.buttons():
        brick.light(Color.RED)

    elif Button.UP in brick.buttons():
        brick.display.image(ImageFile.EV3, Align.TOP_LEFT, clear=False)

    elif Button.DOWN in brick.buttons():
        if brick.battery.voltage() < 7000:
            brick.sound.beep()
    elif Button.CENTER in brick.buttons():
        brick.display.image("MARIO.png")
