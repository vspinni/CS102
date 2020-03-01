//Author: Shravan Pinni
//Date: 10/20/18
//lab 9

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

//Declared arrays used for reference as global constants so they could be used throughout all functions
const string value[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const string suit[4] = {"D","H","S","C"};

//Function Prototypes
int GetRandom(int min, int max); 
string DealCards(int array[], int player);
int ScoreHand(int array[], int player);
void InitializeCards(int array[], int size);

int main(){

	//Seeded rand to get different values every run. Numplayers for the number of players and the score variable that is reset
	//for each player. The decksize is set at a constant of 52 and is made into an array. This array is then initialized with
	//InitializeCards.

	srand(time(0));
	int numPlayers = 2;
	int score;
	const int decksize = 52;
	int cards[decksize];
	InitializeCards(cards, decksize);
	
	//Creating strings to store the player and dealers cards and ints to store their scores.
	string dealerString = "";
	string playerString = "";
	int dealerScore;
	int playerScore;
	string input;

	//Prints the output for dealer.
	cout << setw(15) << left <<  "Dealer has cards"<< setw(2)<< left<< ": "; 
	dealerString += DealCards(cards,1) + " " + DealCards(cards,1);
	dealerScore = ScoreHand(cards, 1);
	cout << setw(20) << left << dealerString << "(" << dealerScore << ")" << endl;

	//Prints output for player.
	cout << setw(15) << left << "You have cards"<< " " << setw(2)<< left<< ": ";
	playerString += DealCards(cards,2) + " " + DealCards(cards,2);
	playerScore = ScoreHand(cards,2);
	cout << setw(20) << left << playerString << "(" << playerScore  << ")" <<  endl;

	//Prompts the player to hit or stand.
	cout << setw(16) << left << "Hit or stand" << "? ";
	cin >> input;
	cout << endl;


	//Makes sure that the player's input is valid.
	while(input != "stand" && input != "hit"){
		cout << setw(16) << left << "Hit or stand"<< "? ";
		cin >> input;
		cout << endl;


	}

	//Gives the player another card and updates their score when they input hit.
	while(input == "hit"){

		playerString += " " + DealCards(cards,2);
		playerScore = ScoreHand(cards, 2);
		dealerScore = ScoreHand(cards,1);
		
		//Shows the updated information
		cout << setw(15) << left << "Dealer has cards" << setw(2) << left << ":" << 
		setw(20) << left << dealerString << "(" << dealerScore << ")" << endl;
		
		cout << setw(15) << left << "You have cards"<< " " << setw(2) << left << ":" << 
		setw(20) << left << playerString << "(" << playerScore << ")" << endl;
		
		//Breaks if the player's score reaches or passes 21.
		if(playerScore >= 21)
			break;
		
		//Prompts the user to hit or stand again
		cout << setw(16) << left << "Hit or stand" << "? ";
		cin >> input;
		cout << endl;
		
		//Makes sure that the player's input is valid while inside the while loop for the hit/stand commands 
		while (input!= "stand" && input != "hit"){
			cout << setw(16) << left << "Hit or stand" << "? ";
			cin >> input;	
			cout << endl;
			
		}	
	}
		//Outputs that the player wins if their score is 21.
		if(playerScore == 21){
			
			cout << "You hit 21, you win!" << endl;

		}

		//Outputs that the player busts if their score is higher than 21.
		else if(playerScore >21){
			
			cout << "Player busts, dealer wins!" << endl;

		}

		//If the player doesn't lose or win after their hits and or stand, the dealer plays.
		else{

			//If the dealer's score is less than 18,they will keep hitting until it is at least 18. The score and string updates
			//to reflect that.
			while(dealerScore<18){
			dealerString += " " + DealCards(cards,1);
			dealerScore = ScoreHand(cards,1);
			
			//Outputs the results of the dealer's hits.
			cout << setw(16) << left << "Dealer hits" << setw(2) << left << ":" << setw(20) << left
			<<  dealerString << "(" << dealerScore << ")" << endl;

			}	

			//If the dealer passes 21, they lose.
			if(dealerScore>21)
				cout << "Dealer busts, player wins!" << endl;
		
			//If the dealer gets exactly 21, they win.
			else if (dealerScore == 21)
				cout << "Dealer hit 21, dealer wins!" << endl;

			//If the dealer's score is equal to the player's score after the dealer finishes hitting, they tie.
			else if(dealerScore == playerScore)
				cout << "Player and dealer draw." << endl;
		
			//If the dealer's score is greater than the player's score, the dealer wins.
			else if(dealerScore > playerScore)
				cout << "Dealer wins!"<< endl;

			//If the dealer's score is less than the player's score, the player wins.
			else 
				cout << "Player wins!" << endl;


		}

}




//GetRandom function which gets a random between a min and max values given
int GetRandom (int min, int max){
	

	return (rand()%(max-min+1)+min);
}

//DealCards function which deals a card from a 52 player deck to a player
string DealCards(int array[],int player){

	int number = GetRandom(0,51);
	int card;
	int cardSuit;
	string cardDealt;
		
	//Makes sure that the card given has not already been given to another player.
	while(array[number]!=0)
		number = GetRandom(0,51);

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

//Initializes an array to 0 for all values
void InitializeCards(int array[], int size){
	for (int i = 0;i<size;i++)
		array[i] = 0;

}

//ScoreHand function looks through the entire array of cards and identifies which have been given to the selected player and then 
//totals up their values.
int ScoreHand(int array[],int player){

	int score = 0;

	for(int i = 0;i<52;i++){
		int card = 0;

		if(array[i] == player){
			card = i%13+1;
			if(card>=10)
				score+=10;
			else
				score+=card;
		}
	}
	return score;

}

