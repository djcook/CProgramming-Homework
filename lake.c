/*
Program Name: lake.c
Programmer: Dylan Cook
Class: CS 3335 A
HW: 02
Problem: 02
Date: 9/23/15
*/

/*
This program is made to use the manning equation to guess
the correct depth at which the flow rate is .1% near 1000
*/
#include <stdio.h>
#include <math.h>
#define S .0015
#define N .014

int main()
{
	float a; //area
	float q; //flow
	float r; //hydrolic radius
	float diff;
	float error;
	float width = 15;
	float guess = 5;

	//solving for the flow
	a = guess * width;
	r = (guess * width) / (2.0 * guess + width);
	q = (1.486 / N) * a * pow(r, .6667) * pow(S, .5);

	printf("At a depth of %f feet, the flow is %f cubic feet per second.\n\n", guess, q );

	printf("Enter your initial guess for the channel depth\n");
	printf("when the flow is 1000.0000 cubic feet per second\n");

	while(1)
	{
		printf("Enter guess> ");
		scanf("%f", &guess);
		
		//solving for the flow
		a = guess * width;
		r = (a) / (2.0 * guess + width);
		q = (1.486 / N) * a * pow(r, .6667) * pow(S, .5);

		diff = 1000.0000 - q;
		error = (diff / 1000.0000) * 100;

		printf("\nDepth: %f Flow: %f cfs Target: 1000.0000 cfs\n", guess, q);
		printf("Different: %f Error: %f percent\n", diff, error);

		//checks if error is less than .1 percernt and not negative
		if(error < .1 && error > 0)
		{
			break;
		}
	}
	return 0;
}
