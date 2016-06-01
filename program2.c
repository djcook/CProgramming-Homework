/*
Program Name: Program2.c
Programmer: Dylan Cook
Class: CS 3335 A
HW: 01
Problem: 02
Date: 9/9/15
*/

#include<stdio.h>

int main()
{
	float x = 0;//x coordinate
	float y = 0;//y coordinate

	//obtaining coordinates
	printf("Please enter an x coordinate\n");
	scanf("%f", &x);
	
	printf("Please enter a y coordinate\n");
	scanf("%f", &y);

	//checking quadrants
	if(x > 0 && y > 0)
	{
		printf("(%.1f , %.1f) is in quadrant I\n", x, y);
	}
	else if(x < 0 && y > 0)
	{
		printf("(%.1f , %.1f) is in quadrant II\n", x, y);
	}
	else if(x < 0 && y < 0)
	{
		printf("(%.1f , %.1f) is int quadrant III\n", x, y);
	}
	else if(x > 0 && y < 0)
	{
		printf("(%.1f , %.1f) is in quadrant IV\n", x, y);
	}
	else if((x == 0) && (y != 0))
	{
		printf("(%.1f , %.1f) is on the y-axis\n", x, y);
	}
	else if((y == 0) && (x != 0))
	{
		printf("(%.1f , %.1f) is on the x-axis\n", x, y);
	}
	else
	{
		printf("(%.1f , %.1f) is on the origin\n", x, y);
	}

	return 0;
}
