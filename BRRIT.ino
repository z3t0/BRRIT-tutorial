// BRRIT sample code
// by Rafi Khan <zetoslab@gmail.com>

/*
 * Description:
 *
 * The robot should be able to move around freely and
 * turn left when it finds and object within a range of 10 cm
 *
 *
 * Parts Used:
 * L298N Dual Motor Controller <http://www.instructables.com/id/Control-DC-and-stepper-motors-with-L298N-Dual-Moto/>
 * HC-SR04 <http://playground.arduino.cc/Code/NewPing>, <https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home>
 */


// Libraries
#include <NewPing/NewPing.h>
#include <Servo.h>

// Variables

// Motor:
int motor_left_pin = 6;
int motor_right_pin = 7;

Servo motor_left;
Servo motor_right;

// Ping:
int echo = 10;
int trig = 9;
int max_distance = 50;
NewPing ping(trig, echo, max_distance); // NewPing setup of pins and maximum distance.

void setup() {
    // Initialise motors
    motor_left.attach(motor_left_pin);
    motor_right.attach(motor_right_pin);

}

void loop() {
    // put your main code here, to run repeatedly:

    if (get_sonar() <= 10) {
        turnLeft()
    }
    else {
        forward();
    }

}

void forward() {
    motor_left.writeMicroseconds(2000);
    motor_right.writeMicroseconds(2000);
}

void turnLeft() {
    motor_left.writeMicroseconds(1000);
    motor_right.writeMicroseconds(2000);
}

int get_sonar() {
    return ping.get_cm();
}
