//Author: Shravan Pinni
//Date: 9/17/18
//Lab 4

#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int main ()
{

//Declaring variables

	double carMiles, carGallons, truckMiles, truckGallons, carCount, truckCount, tempMiles, tempGas;
	string userCommand;

//creating two while loops that terminate with a break condition for when the user enters "done"
	while (1)
	{
		while (1)
		{
			cout << "Enter command: ";
			cin >> userCommand;
			if ((userCommand=="car") ||( userCommand=="truck") ||( userCommand=="done"))
				break;
			else
				cout << "Unknown Command"; 
		}

//creating an if statement for the number of cars, total car miles, and total car gallons
		if (userCommand=="car")
		{
			carCount++;

			cout << "Enter car's miles: ";
			cin >> tempMiles;
			carMiles += tempMiles;

			cout << "Enter car's gallons: ";
			cin >> tempGas;
			carGallons += tempGas;
		}

//creating an if statement for the number of trucks, total truck miles, and total truck gallons		
		if (userCommand=="truck")
		{
			truckCount++;

			cout << "Enter truck's miles: ";
			cin >> tempMiles;
			truckMiles += tempMiles;

			cout << "Enter truck's gallons: ";
			cin>> tempGas;
			truckGallons += tempGas;

		}
//statement breaking the first while loop on the command "done"
		else if (userCommand=="done")
			break;
	}

//upon the user entering done, calculates the MPG for cars and trucks or says no cars or trucks in fleet respectively
	if (userCommand=="done")
	{
		if(carCount > 0)
			cout <<"Average car MPG = " << (carMiles/carGallons)<< endl;
		else
			cout << "Fleet has no cars."<< endl;

		if (truckCount > 0)
			cout << "Average truck MPG = " << (truckMiles/truckGallons) << endl;
		else 
			cout << "Fleet has no trucks." << endl;

	}
	return 0;
	}
