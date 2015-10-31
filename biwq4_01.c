/* 
 * two balls are sitting in contact with one another.
 * ball 1 has a radius of 100mm and a mass of 5kg. 
 * ball 2 has a radius of 150mm and a mass, 16.875kg.
 * 
 * 1.) calculate the force of gravity between the two balls.
 * 
 * 2.) how much smaller (-) or larger (+) would this force be 
 *     if the distance between the cores was doubled? 
 * 
 * 3.) How much smaller (-) or larger (+) would this force be 
 *     if the mass of the balls were doubled, but the radius 
 *     stayed the same (i.e. they are touching)?
 *
 */

#include <stdio.h>
#include <math.h>

#define DEBUG 1
#define SIGN(n) ((grav_force_0 < n) ? '+' : '-')

#define G 6.673E-11 // gravitational constant;

struct ball {
	double radius; // in m;
	double mass; // in kg;
};

double sq(double); // square a number;

int main(void) {
	/* init */
	struct ball ball_1, ball_2, ball_a;
	double answer_1, answer_2, answer_3;
	
	answer_1 = answer_2 = answer_3 = 0;
	ball_1.radius = 100 * 0.001;
	ball_2.radius = 150 * 0.001;
	ball_1.mass = 5;
	ball_2.mass = 16.875;
	ball_a.radius = ball_1.radius + ball_2.radius;
	ball_a.mass = ball_1.mass * ball_2.mass;
	
	/* 1. */
	const double grav_force_0 = G * (ball_a.mass / sq(ball_a.radius));
	answer_1 = grav_force_0;

	/* 2. */
	const double grav_force_1 = G * (ball_a.mass / sq(ball_a.radius * 2));
	answer_2 = (grav_force_0 > grav_force_1) ? 
		(grav_force_0 / grav_force_1) : (grav_force_1 / grav_force_0);

	/* 3. */
	const double grav_force_2 = G * ((ball_a.mass * 4) / sq(ball_a.radius));
	answer_3 = (grav_force_0 > grav_force_2) ? 
		(grav_force_0 / grav_force_2) : (grav_force_2 / grav_force_0);

	/* results */
	printf("1.) %+.10E\n2.) %c%.10E\n3.) %c%.10E\n", 
		answer_1, 
		SIGN(grav_force_1), answer_2, 
		SIGN(grav_force_2), answer_3);
	
	/* debuging */
	#ifdef DEBUG
	#if (DEBUG != 0)
	printf("; grav_force_0: %10E\n; grav_force_1: %10E\n; grav_force_2: %10E\n", 
		grav_force_0, grav_force_1, grav_force_2);
	#endif
	#endif
}

double sq(double n) { 
	return n * n; 
}

