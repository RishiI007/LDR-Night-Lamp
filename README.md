# Automatic Night Lamp using LDR Sensor 💡

An Arduino-based project that automatically switches on a lamp/LED when the environment is dark and turns it off when it is bright, using an **LDR (Light Dependent Resistor)** and a simple voltage divider circuit.

---

## Features
- Automatic detection of ambient light using LDR.
- Turns on an LED (or lamp via relay) in low-light conditions.
- Simple and low-cost design.
- Easily extendable to control real lamps or appliances.

---

## Components Used
- Arduino Uno R3
- LDR (Light Dependent Resistor)
- Resistors: 10 kΩ (voltage divider), 220 Ω (LED current limiting)
- LED (for demonstration, can be replaced with relay + lamp)
- Breadboard & jumper wires

---

## Working Principle
- The **LDR** and **10 kΩ resistor** form a voltage divider connected to the **A0 pin** of Arduino.
- Arduino reads the analog voltage and compares it to a threshold.
- When light intensity falls below the threshold:
  - **LED turns ON** (lamp active).
- When light intensity is above the threshold:
  - **LED turns OFF** (lamp inactive).

---

## Circuit Diagram
![Circuit](./circuit.png)

---

## Arduino Code
See [ldr_night_lamp.ino](./ldr_night_lamp.ino) for the complete code.  

## Simulation
[View Live Simulation on Tinkercad](PASTE-YOUR-SHAREABLE-LINK-HERE)


Main logic:
```cpp
int ldrPin = A0;
int ledPin = 9;
int threshold = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);

  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH); // Dark → Lamp ON
  } else {
    digitalWrite(ledPin, LOW);  // Bright → Lamp OFF
  }
  delay(200);
}
