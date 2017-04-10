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
#include <NewPing.h>
#include <Servo.h>

// Variables

// Motor:
int motor_left_pin = 6;
int motor_right_pin = 5;

int left1 = 1;
int left2 = 2;
int right1 = 3;
int right2 = 4;

Servo motor_left;
Servo motor_right;

// Ping:
int echo = 10;
int trig = 9;
int max_distance = 50;
NewPing ping(trig, echo, max_distance); // NewPing setup of pins and maximum distance.

void setup() {
		pinMode(motor_left_pin, OUTPUT);
		pinMode(motor_right_pin, OUTPUT);

		pinMode(left1, OUTPUT);
		pinMode(left2, OUTPUT);
		pinMode(right1, OUTPUT);
		pinMode(right2, OUTPUT);

    // Initialise motors
    motor_left.attach(motor_left_pin);
    motor_right.attach(motor_right_pin);

		digitalWrite(left1, HIGH);
		digitalWrite(left2, LOW);
		digitalWrite(right1, HIGH);
		digitalWrite(right2, LOW);
		/* writeDirection() */
		pinMode(13, OUTPUT);


}

void loop() {
    // put your main code here, to run repeatedly:

/*         turnLeft(); */
    if (get_sonar() <= 10 && get_sonar() > 1) {
			digitalWrite(13, HIGH);
        turnLeft();
    }
    else {
        forward();
			digitalWrite(13, LOW);
    }

}

void forward() {
		digitalWrite(left1, HIGH);
		digitalWrite(left2, LOW);
		digitalWrite(right1, HIGH);
		digitalWrite(right2, LOW);
}

void turnLeft() {
		digitalWrite(left1, LOW);
		digitalWrite(left2, HIGH);
		digitalWrite(right1, HIGH);
		digitalWrite(right2, LOW);
}

int get_sonar() {
    return ping.ping_cm();
}

void writeDirection(int left, int right) {
		digitalWrite(left1, HIGH);
		digitalWrite(left2, LOW);
		digitalWrite(right1, HIGH);
		digitalWrite(right2, LOW);

}
