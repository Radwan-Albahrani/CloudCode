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

import struct, time, threading, random

# Default values for the bot
MAX_SPEED = 120
MAX_CANNON_SPEED = 10000
MAX_RESET_SPEED = 120
MAX_ROTATION_RESET = -120
TIME_TO_ROTATE = 3.3

# Initialize all the objects
ev3 = EV3Brick()
display = ev3.screen
speaker = ev3.speaker

left_motor = Motor(Port.A)
right_motor = Motor(Port.D)
cannon = Motor(Port.C)

ultrasonic = UltrasonicSensor(Port.S2)
color_sensor = ColorSensor(Port.S1)
gyro = GyroSensor(Port.S3)
lock_cannon = False
def reset_cannon():
    global lock_cannon
    lock_cannon = True
    cannon.run_until_stalled(MAX_CANNON_SPEED)
    cannon.reset_angle(0)
    cannon.run_angle(MAX_RESET_SPEED, MAX_ROTATION_RESET)
    lock_cannon = False

reset_cannon_thread = threading.Thread(target=reset_cannon)

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

# Define the rotation angles
angles = {
    (305, 1): 90,  # Circle button pressed
    (304, 1): 180,  # X button pressed
    (307, 1): 360,  # Triangle button pressed
    (16, -1): -90,  # LEFT dpad
    (17, 1): -180,  # DOWN dpad
    (17, -1): -360  # UP dpad
}

# Define the frequencies for the notes (in Hz)
C6 = 1047
C5 = 523
B5 = 988
B4 = 494
A5 = 880
A4 = 440
F5 = 698
E5 = 659

# Define the rhythm (in ms)
note_duration = 700  # 0.7 seconds
pause_duration = 1000  # calculated based on tempo 160

# Define the melody with pauses between notes
melody = [
    (C6, note_duration), (0, pause_duration), (C6, note_duration), (0, pause_duration), (C6, note_duration), (0, pause_duration), (C5, note_duration), (0, pause_duration),
    (B5, note_duration), (0, pause_duration), (B5, note_duration), (0, pause_duration), (B5, note_duration), (0, pause_duration), (B4, note_duration), (0, pause_duration),
    (A5, note_duration), (0, pause_duration), (A5, note_duration), (0, pause_duration), (A5, note_duration), (0, pause_duration), (A4, note_duration), (0, pause_duration),
    (F5, note_duration), (0, pause_duration), (F5, note_duration), (0, pause_duration), (E5, note_duration), (0, pause_duration), (C6, note_duration), (0, pause_duration),
]
speaker_busy = False
display_busy = False

# Function to play the rocket sound
def play_rocket():
    global speaker_busy
    if speaker_busy:
        return
    speaker_busy = True
    speaker.play_file("assets/missile.wav")
    speaker_busy = False

# Function to play the melody
def play_melody():
    global speaker_busy
    if speaker_busy:
        return
    speaker_busy = True
    for note, duration in melody:
        speaker.beep(note, duration)
    speaker_busy = False

def display_rocket():
    global display_busy
    global display
    if display_busy:
        return
    display.load_image("assets/missile.png")
    time.sleep(2)
    display.clear()

def handle_cannon():
    global lock_cannon
    if lock_cannon:
        return
    cannon.dc(MAX_CANNON_SPEED)
    # Play shooting sound
    play_rocket_thread.start()
    # Display rocket image
    display_rocket_thread.start() # Display missile image
    time.sleep(0.5)
    cannon.reset_angle(0)
    cannon.run_angle(MAX_RESET_SPEED, MAX_ROTATION_RESET)  # Clear the screen
# Threading for the speaker, to ensure the bot can still move around while playing sounds
play_rocket_thread = threading.Thread(target=play_rocket)
play_melody_thread = threading.Thread(target=play_melody)
handle_cannon_thread = threading.Thread(target=handle_cannon)
display_rocket_thread =threading.Thread(target=display_rocket)

# A helper function for converting stick values (0 to 255) to more usable numbers (-100 to 100)
def scale(val, src, dst):
    return (float(val - src[0]) / (src[1] - src[0])) * (dst[1] - dst[0]) + dst[0]

# Function to handle the event data from the file (Controller inputs)
def handle_event(event):
    global running
    global left_speed
    global left_motor
    global right_motor
    global right_speed
    # Place event data into variables
    (tv_sec, tv_usec, ev_type, code, value) = struct.unpack(FORMAT, event)

    # For rotation
    if ev_type == 1 or ev_type == 3:
        angle = angles.get((code, value))
        if angle is not None:
            # Rotate the motor by the corresponding angle
            if angle < 0: # Turn Clockwise
                right_motor.dc(MAX_SPEED)
                left_motor.dc(-MAX_SPEED)
                time.sleep(TIME_TO_ROTATE * (abs(angle)/360))
            else: # Turn Anticlockwise
                right_motor.dc(-MAX_SPEED)
                left_motor.dc(MAX_SPEED)
                time.sleep(TIME_TO_ROTATE * (abs(angle)/360))

    # For button presses
    if ev_type == 1:
        # Fire the cannon if the left bumper is pressed
        if code == 310 and value == 0:
            handle_cannon_thread.start()

        # Play the melody if right bumper is pressed
        elif code == 311 and value == 0:
            play_melody_thread.start()

        # Stop the bot when the PS Home button is pressed
        elif code == 316 and value == 0:
            running = False

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


# Function to check the distance and avoid obstacles
def check_distance():

    if ultrasonic.distance() < 120:

        # Generate a small random factor between -0.2 and 0.2
        # This is so that the bot doesn't always turn the same way, to avoid getting stuck
        random_factor = random.uniform(-0.2, 0.2)

        # Apply the random factor to the motor speeds
        left_motor.dc((-MAX_SPEED) * (1 + random_factor))
        right_motor.dc((-MAX_SPEED) * (1 - random_factor))

        left_speed = 0
        right_speed = 0
        time.sleep(1)

        # Set motor speed
        left_motor.dc(left_speed)
        right_motor.dc(right_speed)

# Function to check the color sensor and stop the bot
def handle_color_sensor():

    # if any reflection is detected, move forward
    if color_sensor.reflection():

        # Generate a small random factor between -0.2 and 0.2
        # This is so that the bot doesn't always turn the same way, to avoid getting stuck
        random_factor = random.uniform(-0.2, 0.2)

        # Apply the random factor to the motor speeds
        left_motor.dc((MAX_SPEED) * (1 + random_factor))
        right_motor.dc((MAX_SPEED) * (1 - random_factor))

        time.sleep(1)

        # Set motor speed to 0
        left_motor.dc(0)
        right_motor.dc(0)

        return True
    return False

# ----------------------------------------------------------------
# Ensure the bot is set to running at the start of the code.
running = True

# Function to handle the event loop  - Threading
def event_loop():
    while running:
        ready_to_read = True
        if ready_to_read:
            event = in_file.read(EVENT_SIZE)
            handle_event(event)

# Function to check the distance and avoid obstacles - Threading
def distance_check_loop():
    while running:
        check_distance()
        time.sleep(0.1)  # Add a short delay to prevent the loop from running too fast

# Function to check the color sensor and stop the bot - Threading
def color_sensor_loop():
    while running:
        handle_color_sensor()
        time.sleep(0.1)  # Add a short delay to prevent the loop from running too fast

def say_hello():
    global speaker_busy
    global lock_cannon
    global cannon
    speaker_busy = True
    speaker.set_volume(200)
    while lock_cannon:
        pass
    speaker.say("Hello!")
    lock_cannon = True
    for i in range(2):
        cannon.dc(MAX_SPEED/2)
        time.sleep(0.1)
        cannon.dc(-MAX_SPEED/2)
    lock_cannon = False
    reset_cannon_thread.start()
    speaker.set_volume(20)
    speaker_busy = False

# Start the threads
event_thread = threading.Thread(target=event_loop)
distance_thread = threading.Thread(target=distance_check_loop)
button_thread = threading.Thread(target=color_sensor_loop)
hello_thread = threading.Thread(target=say_hello)



hello_thread.start()
event_thread.start()
distance_thread.start()
button_thread.start()


# Continue as long as running is True
while running:
    continue

# Once shut down, say goodbye and close the file
speaker.set_volume(100)
speaker.say("Goodbye!")

in_file.close()
