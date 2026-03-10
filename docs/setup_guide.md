# Setup Guide

## Purpose

This guide explains how to assemble and test the Arduino Recycling Sorter prototype.

## Wiring Overview

### Ultrasonic Sensor

- VCC → 5V
- GND → GND
- Trig → pin 9
- Echo → pin 10

### Inductive Metal Sensor

- VCC → sensor-rated supply
- GND → GND
- Output → pin 7

### Servo Diverter

- Signal → pin 6
- Power → 5V
- Ground → GND

## Build Steps

1. Mount the ultrasonic sensor above or near the item path
2. Position the metal sensor where passing objects can be detected
3. Install the servo-driven sorting gate or diverter
4. Connect all sensors and actuators to the Arduino
5. Upload `recycling_sorter.ino`
6. Open the Serial Monitor at `9600` baud
7. Test with small metal and non-metal objects

## Validation

Before relying on the prototype, verify:

- object detection occurs at the expected distance
- metal detection behaves consistently
- servo routing positions are repeatable
- objects physically fall into the intended bins
