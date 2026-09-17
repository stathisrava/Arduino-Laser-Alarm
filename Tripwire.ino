// ========================================
// LASER TRIPWIRE ALARM
// ========================================

// PINS
const int triggeredLED = 7;
const int triggeredLED2 = 8;

const int RedLED = 4;
const int GreenLED = 5;

const int inputPin = A0;
const int speakerPin = 12;
const int armButton = 6;


// SETTINGS
int threshold = 0;
int sensitivity = 100;


// SYSTEM STATUS
bool isArmed = false;
bool alarmTriggered = false;


// ========================================
// SETUP
// ========================================

void setup() {

  pinMode(triggeredLED, OUTPUT);
  pinMode(triggeredLED2, OUTPUT);

  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);

  pinMode(speakerPin, OUTPUT);
  pinMode(armButton, INPUT);

  Serial.begin(9600);


  // Start UNARMED
  isArmed = false;
  alarmTriggered = false;

  digitalWrite(RedLED, HIGH);
  digitalWrite(GreenLED, LOW);

  digitalWrite(triggeredLED, LOW);
  digitalWrite(triggeredLED2, LOW);


  Serial.println("LASER TRIPWIRE");
  Serial.println("SYSTEM UNARMED");


  // Calibrate sensor
  calibrate();

  Serial.println("CALIBRATION COMPLETE");
  Serial.println("SYSTEM UNARMED");
  Serial.println("Press button to ARM.");
}


// ========================================
// LOOP
// ========================================

void loop() {

  int reading = analogRead(inputPin);


  // ----------------------------------------
  // BUTTON
  // ----------------------------------------

  if (digitalRead(armButton) == HIGH) {

    delay(200);


    // If alarm is sounding
    if (alarmTriggered == true) {

      // Stop alarm
      alarmTriggered = false;
      isArmed = false;

      noTone(speakerPin);

      digitalWrite(triggeredLED, LOW);
      digitalWrite(triggeredLED2, LOW);

      digitalWrite(RedLED, HIGH);
      digitalWrite(GreenLED, LOW);

      Serial.println("ALARM STOPPED");
      Serial.println("SYSTEM UNARMED");
    }


    // If system is armed
    else if (isArmed == true) {

      // Unarm it
      isArmed = false;

      digitalWrite(RedLED, HIGH);
      digitalWrite(GreenLED, LOW);

      Serial.println("SYSTEM UNARMED");
    }


    // If system is unarmed
    else {

      // Arm it
      isArmed = true;

      digitalWrite(RedLED, LOW);
      digitalWrite(GreenLED, HIGH);

      Serial.println("SYSTEM ARMED");
      Serial.println("LASER TRIPWIRE ACTIVE");
    }


    // Wait until button is released
    while (digitalRead(armButton) == HIGH) {
      delay(10);
    }
  }


  // ----------------------------------------
  // LASER TRIPWIRE
  // ----------------------------------------

  if (isArmed == true && alarmTriggered == false) {

    // Laser is blocked
    if (reading < threshold) {

      alarmTriggered = true;

      Serial.println();
      Serial.println("==============================");
      Serial.println("!!! LASER BEAM BREACHED !!!");
      Serial.println("!!! ALARM ACTIVATED !!!");
      Serial.println("==============================");
      Serial.println();
    }
  }


  // ----------------------------------------
  // SIREN
  // ----------------------------------------

  if (alarmTriggered == true) {

    // High pitch
    for (int frequency = 800; frequency <= 1800; frequency += 20) {

      // Button stops alarm
      if (digitalRead(armButton) == HIGH) {
        return;
      }

      tone(speakerPin, frequency);

      digitalWrite(triggeredLED, HIGH);
      digitalWrite(triggeredLED2, LOW);

      delay(5);
    }


    // Low pitch
    for (int frequency = 1800; frequency >= 800; frequency -= 20) {

      // Button stops alarm
      if (digitalRead(armButton) == HIGH) {
        return;
      }

      tone(speakerPin, frequency);

      digitalWrite(triggeredLED, LOW);
      digitalWrite(triggeredLED2, HIGH);

      delay(5);
    }
  }
}


// ========================================
// CALIBRATION
// ========================================

void calibrate() {

  Serial.println();
  Serial.println("CALIBRATING...");
  Serial.println("Keep laser on the sensor.");

  delay(1000);


  long total = 0;


  // Take 20 sensor readings
  for (int i = 0; i < 20; i++) {

    int reading = analogRead(inputPin);

    total = total + reading;

    delay(100);
  }


  // Average laser reading
  int laserLevel = total / 20;


  // Trigger when reading drops below this
  threshold = laserLevel - sensitivity;


  if (threshold < 0) {
    threshold = 0;
  }


  Serial.print("Laser level: ");
  Serial.println(laserLevel);

  Serial.print("Trigger threshold: ");
  Serial.println(threshold);

  Serial.println();
}
