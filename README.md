# Laser Tripwire Alarm

An Arduino-based laser tripwire security alarm. A laser is aimed at a light sensor, and when the beam is interrupted, the system activates a sweeping siren and flashing LEDs.

## 🎥 Demo

<!-- Upload your short demo video here by dragging the MP4 into GitHub's README editor -->

https://github.com/user-attachments/assets/YOUR-VIDEO-ID

## 📸 Wiring Diagram

![Wiring Diagram](wiring-diagram.png)

## ⚙️ How It Works

The system uses a light sensor to detect the laser beam.

* 🔴 **Red LED** → System is **unarmed**
* 🟢 **Green LED** → System is **armed**
* 🔦 **Laser on sensor** → Everything is normal
* ✋ **Laser beam blocked** → Alarm activates
* 🚨 **Buzzer** → Plays a sweeping siren
* 💡 **Two LEDs** → Flash while the alarm is active
* 🔘 **Button** → Arms, disarms, or stops the alarm

The system starts **unarmed** when powered on.

### 1. Power On

The Arduino starts in the unarmed state.

The red LED turns on.

During startup, the system calibrates the light sensor while the laser is pointing at it.

### 2. Arm the System

Press the button once.

The system becomes armed and the green LED turns on.

```text
SYSTEM ARMED
LASER TRIPWIRE ACTIVE
```

### 3. Trigger the Alarm

If something blocks the laser beam, the light level detected by the sensor drops below the calibrated threshold.

The alarm activates:

* The buzzer produces a sweeping siren
* The two alarm LEDs flash
* A breach message is sent to the Serial Monitor

```text
!!! LASER BEAM BREACHED !!!
!!! ALARM ACTIVATED !!!
```

### 4. Stop the Alarm

Press the button.

The siren stops, the alarm LEDs turn off, and the system returns to the unarmed state.

You can then press the button again to arm the system.

## 🧠 Calibration

When the Arduino starts, it takes **20 readings** from the light sensor while the laser is hitting it.

The readings are averaged to determine the normal laser level.

The trigger threshold is then calculated using:

```cpp
threshold = laserLevel - sensitivity;
```

The current sensitivity value is:

```cpp
int sensitivity = 100;
```

A lower sensor reading than the threshold means the laser beam has been interrupted.

## 🔌 Pin Configuration

| Component     | Arduino Pin |
| ------------- | ----------: |
| Trigger LED 1 |           7 |
| Trigger LED 2 |           8 |
| Red LED       |           4 |
| Green LED     |           5 |
| Light Sensor  |          A0 |
| Buzzer        |          12 |
| Arm Button    |           6 |

## 🛠️ Requirements

* Arduino board
* Light sensor
* Laser module
* Buzzer
* Push button
* 2 × alarm LEDs
* Red LED
* Green LED
* Resistors
* Jumper wires
* Breadboard

## 📚 Libraries

No external libraries are required.

The project uses Arduino's built-in functions such as:

```cpp
analogRead()
digitalRead()
digitalWrite()
tone()
noTone()
```

## 🚀 Getting Started

1. Build the circuit using the wiring diagram above.
2. Upload the Arduino code.
3. Point the laser directly at the light sensor.
4. Power on the Arduino.
5. Wait for calibration to finish.
6. Press the button to arm the system.
7. Block the laser beam to test the alarm.
8. Press the button to stop the alarm.

## 📜 License

This project is open source. Feel free to modify and improve it for your own projects.
