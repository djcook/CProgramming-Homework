/*
Pragram Name: Program1.c
Programmer Name: Dylan Cook
Class: CS 3335 A
HW: 01
Problem: 01
Date: 9/3/15
*/

#include<stdio.h>

int main()
{
	float scale; //eathquake scale vairable

	//obtaining earthquake scale variable
	printf("Input an Earthquake scale number\n");
	scanf("%f", &scale);

	//checking the category of earthquake
	if(scale < 5.0)
	{
		printf("Little or no damage\n");
	}
	else if(5.0 <= scale && scale < 5.5)
	{
		printf("Some damage\n");
	}
	else if(5.5 <= scale && scale < 6.5)
	{
		printf("Serious damage: walls may crack or fall\n");
	}
	else if(6.5 <= scale && scale < 7.5)
	{
		printf("Disaster: houses and building may collapse\n");
	}
	else
	{
		printf("Catastrophe: most buildings destroyed\n");
	}

	return 0;
}
