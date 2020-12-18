/**
* @link https://github.com/Almadef/car/
* @copyright Copyright (c) 2019 Chuvashov Mikhail
* @license https://github.com/Almadef/car/blob/master/LICENSE
*/

// Connecting Bluetooth library
#include <SoftwareSerial.h>

// Driving motor (Motor A) pins
#define ROTATION_MOTOR_A_1 3
#define ROTATION_MOTOR_A_2 4
#define SPEED_MOTOR_A 2

// Rotating motor (Motor B) pins
#define ROTATION_MOTOR_B_1 5
#define ROTATION_MOTOR_B_2 6
#define SPEED_MOTOR_B 7

// Bluetooth pins
#define TxD 8
#define RxD 9

SoftwareSerial bluetoothSerial(TxD, RxD);

char c;

void setup()
{
    bluetoothSerial.begin(9600);
    Serial.begin(9600);
    pinMode(ROTATION_MOTOR_A_1, OUTPUT);
    pinMode(ROTATION_MOTOR_A_2, OUTPUT);
    pinMode(SPEED_MOTOR_A, OUTPUT);
    pinMode(ROTATION_MOTOR_B_1, OUTPUT);
    pinMode(ROTATION_MOTOR_B_2, OUTPUT);
    pinMode(SPEED_MOTOR_B, OUTPUT);  
}

void loop()
{
    if (bluetoothSerial.available())
    {
        c = bluetoothSerial.read();
        Serial.println(c);
        if (c == '0')
        {
            // Stop motors
            analogWrite(SPEED_MOTOR_A, 0);
            analogWrite(SPEED_MOTOR_B, 0);
        }
        if (c == '1')
        {
            // Motor B left
            analogWrite(SPEED_MOTOR_B, 255);
            digitalWrite(ROTATION_MOTOR_B_1, HIGH);
            digitalWrite(ROTATION_MOTOR_B_2, LOW);
        }
        if (c == '2')
        {
            // Motor B right
            analogWrite(SPEED_MOTOR_B, 255);
            digitalWrite(ROTATION_MOTOR_B_1, LOW);
            digitalWrite(ROTATION_MOTOR_B_2, HIGH);
        }
        if (c == '3')
        {
            // Motor A up
            analogWrite(SPEED_MOTOR_A, 255);
            digitalWrite(ROTATION_MOTOR_A_1, LOW);
            digitalWrite(ROTATION_MOTOR_A_2, HIGH);
        }
        if (c == '4')
        {
            // Motor A down
            analogWrite(SPEED_MOTOR_A, 255);
            digitalWrite(ROTATION_MOTOR_A_1, HIGH);
            digitalWrite(ROTATION_MOTOR_A_2, LOW);
        }
    }
}
