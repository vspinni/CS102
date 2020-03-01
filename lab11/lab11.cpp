//Author: Shravan Pinnni
//Date: 11/6/18
//Lab 11

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Declaring and initializing the ticket fees
const double INTERSTATE = 5.2252;
const double HIGHWAY = 9.4412;
const double RESIDENTIAL = 17.1525;
const double OTHER = 12.152;

//function prototypes
bool Read(Database &d, istream &in);
bool Write(const vector<Ticket> &tickets, ostream &out);
int Encode(const Date &d);

struct Date{
	int month;
	int day;
	int year;

};

struct Ticket{
	string citationNumber;
	Date citationDate;
	int clockedSpeed;
	int limitSpeed;
	char roadType;
	
};

class Database{
	vector<Ticket> tickets;
	public:
		void add_ticket(const Ticket &tick);
		vector<Ticket> gen_report(Date start, Date end);

};

int main (int argc, char *argv[]){


}

void Database::add_ticket(const Ticket &tick){
	tickets.push_back(tick);

}

	
}

bool Read(Database &d, istream&in){

}

bool Write(const vector<Ticket> &tickets, ostream &out){

}

int Encode(const Date &d){
	int integerDate = d.year*10000;
	integerDate += d.month*100;
	integerDate +=d.day;
	return integerDate;
}



