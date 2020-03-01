//Author: Shravan Pinni
//Date: 10/16/18
//lab 8

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

//Declared all of the arrays used as global variables so they could be used throughout all functions
string value[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string suit[4] = {"D","H","S","C"};
int cards[52];

//GetRandom function which gets a random between a min and max values given
int GetRandom (int min, int max){
	

	return (rand()%(max-min)+min);
}

//DealCards function which deals a card from a 52 player deck to a player
string DealCards(int array[],int player){

	int number = GetRandom(0,52);
	int card;
	int cardSuit;
	string cardDealt;
		
//Makes sure that the card given has not already been given to another player.
	while(array[number]!=0)
		number = GetRandom(0,52);

//records the card so a future player doesn't get it.
    array[number] = player;

//The modulus operator gives us the card number and the division operator gives us the suit.
	card = number%13;
	cardSuit = number/13;

//The values are then used as indexes for the suit and value arrays to get the value of the card given. 
	cardDealt = value[card];
	cardDealt += suit[cardSuit];


	return cardDealt;

}

//ScoreHand function looks through the entire array of cards and identifies which have been given to the selected player and then 
//totals up their values.

int ScoreHand(int array[],int player){

	int score = 0;

	for(int i = 0;i<52;i++){
		int card = 0;

		if(array[i] == player+1){
			card = i%13+1;
			if(card>=9)
				score+=10;
			else
				score+=card;
		}
	}
	return score;

}

int main(){

//Seeded rand to get different values every run. Numplayers for the number of players and the score variable that is reset
//for each player.

	srand(time(0));
	int numPlayers = 0;
	int score;


	cout << "How many players? ";
	cin >> numPlayers;

//The while loop makes sure that the players are less than or equal to 26.
	while(numPlayers>26){

		cout<< "How many players? ";
		cin >> numPlayers;
	}

//Prints the output for each player.
	for(int i = 0;i<numPlayers;i++){

		cout << "Player " << i+1 << " has cards: ";
		for(int j = 0;j<2;j++){
			cout << DealCards(cards,i+1) << " ";
			}
//The width is set to 14 beause the cards take up 3 characters including spaces themselves so the score has 14 spaces left 
//out of the 20 spaces wanted.
		cout << setw(14)<<"("<< ScoreHand(cards,i) <<")" <<  endl;

	}	

}
