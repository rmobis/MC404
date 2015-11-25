#include "api_robot.h"

#define min(x, y) (((x) < (y)) ? (x) : (y))

#define MIN_DISTANCE 2000

void _start() {
	unsigned short leftFrontal, rightFrontal;
	unsigned char rightSpeed;

	while (1) {
		leftFrontal = read_sonar(3);
		rightFrontal = read_sonar(4);

		if (min(leftFrontal, rightFrontal) < MIN_DISTANCE) {
			rightSpeed = 0;
		} else {
			rightSpeed = 18;
		}

		set_speed_motors(18, rightSpeed);
	}
}