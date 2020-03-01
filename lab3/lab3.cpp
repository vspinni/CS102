//Author:Shravan Pinni
//Date:9/5/18
//Lab 3

#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int main ()
{
//Creating variables for the operands and operation
	char operation;
	double operand1;
	double operand2;

//Asks the user to input the left operand and checks for an invalid operand.
	cout << "Enter the left operand: ";
	if (!(cin>> operand1))
	{
		cout << "Invalid left operand.\n";
		return 0;
	}

//Asks the user to enter the operation.
	cout << "Enter the operation: ";
	cin >> operation;

/*Asking the user to enter the right operand as long as the operation that
they chose was not the absolute value. Also checks for an invalid operand
here.	*/
	if ((operation != 'B') && (operation != 'b') && (operation != '|'))
	{
		cout << "Enter the right operand: ";
		if(!(cin >> operand2))
		{	
			cout << "Invalid right operand.\n";
			return 0;
		}
	}

//The switch statement for the different potential operations and a default
//that outputs Unknown Operation.
	switch(operation)
	{
		case 'A':
		case 'a':
		case '+':
			cout << "Result = " << (operand1 + operand2) << endl;
			return 0;
			break;
		case 'S':
		case 's':
		case '-':
			cout << "Result = " << (operand1 - operand2) << endl;
			return 0;
			break;
		case 'M':
		case 'm':
		case 'x':
		case '*':
			cout << "Result = " << (operand1 * operand2) << endl;
			return 0;
			break;
		case 'D':
		case 'd':
		case '/':
			cout << "Result = " << (operand1 / operand2) << endl;
			return 0;
			break;
		case 'B':
		case 'b':
		case '|':
		cout << "Result = " << abs(operand1) << endl;
			return 0;
			break;
		default: cout << "Unknown operation.\n";
			 return 0;
			 break;

	}
	return 0;
}	
