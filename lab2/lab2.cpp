//Author: Shravan Pinni
//Date: August 29, 2018
//Lab2
//
#include <string>
#include <iostream>

using namespace std;
int main()
{
	string firstName;
	string middleName;
	
	int userAge;
	
	int streetNumber;
	string streetName;
	string streetType;
	
	cout << "Enter your first and middle names: ";
	cin >> firstName;
	cin >> middleName;
	
	cout << "Enter your age: ";
	cin >> userAge;
	
	cout << "Enter your street number, name, and type: ";
	cin >> streetNumber;
	cin >> streetName;
	cin >> streetType;
	cout << endl;
	cout << endl;

	cout << "Your movie star name is " << streetName << " "
		<< middleName << "." << endl;
	cout << "You will play a " << (streetNumber % userAge * 3) << " old." 
		<< endl;
	cout << "Your address is " << (userAge * 700 / streetNumber) << " " << 
		firstName << " " <<  streetType << ".";

	

}
