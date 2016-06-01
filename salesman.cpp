/*
Program Name: salesman.cpp
Programmer: Dylan Cook
Class: CS 3335 A
HW: 05
Problem: 01
Date: 12/1/15
*/
#include <iostream>
using namespace std;

const int MAX_NAME = 20;
const int MAX_SALESMEN = 5;
const int NOT_FOUND = -1;

struct Seller
{
	float sales;               // running total of money he collected
	float time;                // running total of time, in hours
	char name[MAX_NAME + 1];   // name of the salesman
};

struct ListOfSalesmen
{
	int num;                  // number of salesmen in the list
	Seller salesman[MAX_SALESMEN];
};

void InitSeller(Seller & s, const char name[])
{
	// Initializes the Salesman's name to name.  
	// Initializes the Salesman's sales and time to 0.0.
	strcpy(s.name,name);
	s.time = 0.0;
}

void UpdateSales(Seller & s, float sales, float time)
{
	// Adds the money and time to the salesman's accumulated sales and time.
	s.sales += sales;
	s.time += time;
}

bool SellerHasName(const Seller & s, const char name[])
{
	// Returns true if the salesman's name is the same as name; false otherwise.
	if(strcmp(s.name,name) == 0)
	{
		return true;
	}
	return false;
}

float SalesValue(Seller & s)
{
	// Returns sales per hour for the salesman.
	// Returns 0.0 if the salesman's time is 0.0.
	// It also zeroes the salesman's sales & time when done calculating.
	if(s.time == 0.0)
	{
		return 0.0;
	}
	return s.sales / s.time;
}

int Search(ListOfSalesmen & l, const char name[])
{
	//Check through the salesman list to see if the name is found
	//if the name is found return the index
	//if not return Not Found
	int x; //loop variable and index for person
	for(x = 0; x < MAX_SALESMEN; x++)
	{
		if(SellerHasName(l.salesman[x], name))
		{
			return x;
		}
	}
	return NOT_FOUND;
}

int main()
{
	//initializing variables
	char cmd;
	char name[MAX_NAME];

	ListOfSalesmen salesList;
	salesList.num = 0;

	while(cmd != 'Q')
	{
		cin >> cmd;
		if(cmd == 'A')
		{
			//if cmd is A check to see if the name is in the list
			//and if the list is full
			//if neither then add the salesman
			cin >> name;
			if(Search(salesList, name) != NOT_FOUND)
			{
				cout << name << " is already in the list." << endl;
			}
			else if (salesList.num >= MAX_SALESMEN)
			{
				cout << name << " not added. List is full." << endl;
			}
			else
			{
				InitSeller(salesList.salesman[salesList.num], name);
				cout << name << " is salesman " << salesList.num << endl;
				salesList.num = salesList.num + 1;
			}
		}

		if(cmd == 'O')
		{
			//Check to see if the person is not found
			// if person is found show their Sales value
			//then change time and sales to 0
			cin >> name;
			int x;
			x = Search(salesList, name); //index of person if found
			
			if(x == NOT_FOUND)
			{
				cout << "Cannot output. " << name << " is not in the list." << endl;
			}
			else
			{
				cout << name << ":" << " $" << SalesValue(salesList.salesman[x]) << " per hour" << endl;
				salesList.salesman[x].sales = 0.0;
				salesList.salesman[x].time = 0.0;
			}
		}

		if(cmd == 'U')
		{
			//Check to see if person is not found
			// if person is found update their sales and time
			float sales;
			float time;
			cin >> name >> sales >> time;

			int x;
			x = Search(salesList, name); // index for person if found

			if(x == NOT_FOUND)
			{
				cout << "Cannot output. " << name << " is not in the list." << endl;
			}
			else
			{
				UpdateSales(salesList.salesman[x], sales, time);
				cout << "Salesperson " << name << " sold $" << sales << " of toys in " << time << " hours" << endl;
			} 
		}
	}
	return 0;
}
