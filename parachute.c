/*
Program Name: parachute.c
Programmer Name: Dylan Cook
Class CS 3335 A
HW: 03
Problem: 01
Date: 10/14/15
*/

//This program was written to guess the size of a parachute needed to land safely with a safe fps
#include <stdio.h>
#include <math.h>

#define MAX_TRY 5
#define MIN_FPS 14.0
#define MAX_FPS 15.0
#define FPS_CON1 442.2 //constant in fps formula multiplying with sqrt
#define FPS_CON2 16 //constant that the weight is divided by in the sqrt of the fps formula

float GetCargo()
{
	float weight;

	printf("Enter weight of cargo in ounces: ");
	scanf("%f", &weight);

	//making sure weight is positive and above 0
	while(weight <= 0.0)
	{
		printf("ERROR!!!!  BAD WEIGHT\n\n");
		printf("Enter weight of cargo in ounces: ");
		scanf("%f", &weight);
	}
	return weight;
}

float GetChuteSize(int count)
{
        float size;

        printf("Try %d \n", count);
        printf("Enter chute size in square feet: ");
        scanf("%f", &size);

	//making sure size is positive and above 0
        while(size <= 0.0)
        {
                printf("ERROR!!!! BAD PARACHUTE SIZE\n\n");
                printf("Try %d\n", count);
                printf("Enter chute size in square feet: ");
                scanf("%f", &size);
        }
        return size;
}

float Computefps(float weight, float size)
{
        float fps;
	
	//solving for the fps
        fps = (FPS_CON1 * sqrt(weight / FPS_CON2)) / size;
        printf("Falling at %.4f feet/sec.\n", fps);

        return fps;
}

int main()
{
        float weight = GetCargo();
        float size;
        float fps;
        int count = 1;

        while(count <= MAX_TRY)
        {
                size = GetChuteSize(count);
                fps = Computefps(weight, size);
		
		//checking if fps is just right
                if(fps <= MIN_FPS)
                {
                        printf("TOO SLOW...Drifting too much...you need a smaller chute.\n");
                }
                else if(fps >= MAX_FPS)
                {
                        printf("SPLAT!!!!...You need a bigger chute\n");
                }
                else
                {
                        printf("Nice landing!!!\n");
                        break;
                }

		if(count == MAX_TRY)
		{
			printf("Bad landing skills...Bye\n");
		}
                count++;
        }
        return 0;
}


