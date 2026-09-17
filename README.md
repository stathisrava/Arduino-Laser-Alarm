# Laser Tripwire Alarm

An Arduino-based laser tripwire security alarm. A laser is aimed at a light sensor, and when the beam is interrupted, the system activates a sweeping siren and flashing LEDs.

## 🎥 Demo

<!-- Upload your short demo video here by dragging the MP4 into GitHub's README editor -->

https://github.com/user-attachments/assets/YOUR-VIDEO-ID  


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


## How It Works

The system uses a light sensor to detect the laser beam.

**Red LED** → System is unarmed    
**Green LED** → System is armed    
**Laser on sensor** → Everything is normal   
**Laser beam blocked** → Alarm activates  
**Buzzer** → Plays a sweeping siren  
**Two LEDs** → Flash while the alarm is active  
**Button** → Arms, disarms, or stops the alarm  

The system starts **unarmed** when powered on.


## Serial Monitor Output 
<img width="552" height="591" alt="image" src="https://github.com/user-attachments/assets/d88f5378-6a0c-40f5-8581-9c652d649a3b" />


