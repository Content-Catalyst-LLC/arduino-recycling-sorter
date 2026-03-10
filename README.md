# Arduino Recycling Sorter

An Arduino-based recycling sorter for sensor-based waste classification with reproducible firmware, calibration notes, and sustainability-oriented sorting system documentation.

This project is designed as a reproducible prototype for engineers, students, and researchers interested in embedded sorting systems, environmental automation, and waste-handling experiments.

## Overview

The system uses low-cost sensors and a servo-based diverter to detect and route small waste items into different categories.

At a systems level, the architecture can be summarized as:

Object Input → Sensor Layer → Arduino → Sorting Logic → Servo / Diverter Action

## Features

- proximity-based object detection
- basic material sorting logic
- servo-based diversion mechanism
- Arduino-based control loop
- extensible for improved sensing, logging, or automation

## Repository Structure

- `firmware/` — Arduino sorting firmware
- `docs/` — setup, calibration, and deployment documentation
- `data/` — example sorting events
- `hardware/` — wiring diagrams and schematics
- `BOM.csv` — bill of materials

## Notes

This is a prototype reference design, not an industrial recycling system. Engineers adapting it for more realistic sorting tasks should validate sensor accuracy, object geometry assumptions, actuator repeatability, and throughput behavior.

## License

This project is released under the MIT License.

See `LICENSE` for details.
