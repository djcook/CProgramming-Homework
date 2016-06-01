/*
Program Name: vander.c
Programmer: Dylan Cook
Class: CS 3335 A
HW: 02
Problem: 01
Date: 9/23/15
*/

//The program is made to show the Van der Waals formula
#include <stdio.h>
#include <math.h>

#define A 3.592
#define B 0.0427
#define R 0.08206

int main()
{
	float n; //moles
	float kelvin;
	float initVol;
	float finalVol;
	float increment;
	float p = 0; //pressure

	printf("Please enter at the prompts the number of moles of carbon\n");
	printf("dioxide, the absolute temperature, the initial volume in\n");
	printf("milliliters, the final volume, and the increment volume\n");
	printf("between lines of the table.\n\n");

	printf("Quantity of carbon dioxide (moles)> ");
	scanf("%f", &n);

	printf("Temperature (kelvin)> ");
	scanf("%f", &kelvin);

	printf("Initial volume (milliliters)> ");
	scanf("%f", &initVol);

	printf("Final volume (milliliters)> ");
	scanf("%f", &finalVol);

	printf("Volume increment (milliliters)> ");
	scanf("%f", &increment);

	//Prepping the output table
	printf("\n%.4f moles of carbon dioxide at %.0f kelvin\n\n", n, kelvin);
	printf("Volume (ml)\tPressure (atm)\n");

	while(initVol <= finalVol)
	{
		p = ((n * R * kelvin) / ((initVol * .001) - (B * n))) - ((A * (pow(n, 2))) / (pow((initVol * .001), 2)));
		printf("   %.0f\t\t   %.4f\n", initVol, p);
		initVol += increment;
	}
	return 0;
}
