# Bus Overload Detectionsystem
A bus overload detction system is designed to prevent buses from carrying too many passengers, ensuring passenger safety and compliance with Total capacity of the vehicle

Components:

1.Arduino Uno
2.IR Sensor
3.Buzzer
4.Red LED
5.Green LED
6.Liquid Crystal Display (LCD) with I2C interface
7.Breadboard

Connection Details:

1.Connect the VCC of the IR Sensor to +5V on Arduino.

2.Connect the GND of the IR Sensor to GND on Arduino.

3.Connect the Signal (or OUT) of the IR Sensor to a digital pin (e.g., pin 2) on Arduino.

4.Connect the positive (longer leg) of the Buzzer to a digital pin (e.g., pin 4) on Arduino.

5.Connect the negative (shorter leg) of the Buzzer to GND on Arduino.

6.Connect the Anode of the Red LED to a digital pin (e.g., pin 7) on Arduino.

7.Connect the Cathode of the Red LED to GND on Arduino via a current-limiting resistor.

8.Connect the Anode of the Green LED to a digital pin (e.g., pin 8) on Arduino.

9.Connect the Cathode of the Green LED to GND on Arduino via a current-limiting resistor.

10.Connect the I2C lines (SDA and SCL) of the LCD to the corresponding pins on Arduino (A4 and A5).

11.Connect the VCC and GND of the LCD to +5V and GND on Arduino.

Working:
The IR sensor detects the presence of a person in front of it.
When a person is detected, the passenger count is incremented, and the LCD and Serial Monitor are updated.
If the passenger count reaches the threshold (e.g., 10), the system activates the buzzer, turns on the red LED, displays "BUS FULL!" on the LCD, and resets the passenger count after a delay.
If the passenger count is below the threshold, the system displays the current count on the LCD and activates the green LED.
