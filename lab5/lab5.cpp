//Author: Shravan Pinni
//Date: 9/21/18
//Lab 5

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main ()
{

//Creating the vectors and arrays to hold the scores and player names and
//other variables used
vector<string> players(0);
vector<int> totalScore(1,0); 
string userInput;
int scores[21];
int numPlayers=0;
int frame;
int playerSum;

//while loop
	while(1)
	{
		frame=1;
		cout << "Enter player's name (done for no more players): ";
		cin >> userInput;

//while look broken by the user inputting "done"
		if(userInput=="done"){
			if(numPlayers==0)
			cout<< "No players were entered."<<endl;
			break;
		}	
		players.push_back(userInput);
		numPlayers++;

//for loop to input the scores for the 10 frames for a single player
		for(int i=0;i<10;i++)
		{	
//if statement to the code inside for the first 9 frames since the 10th frame
//may have a third roll
			if(frame<10){
				cout << "Enter score for frame " << frame<< ", roll 1: ";
				cin>> scores[2*i];

				if(scores[2*i]==10)
				{	
					scores[2*i+1]=0;
				}
				else
				{	
					cout << "Enter score for frame "<< frame << ", roll 2: ";
					cin >> scores[2*i+1];
				}	
				
			}
//else statement to account for the potential outcomes in the 10th frame
//such as rolling a spare, strike, or neither
			else
			{				
					cout << "Enter score for frame 10, roll 1: ";
					cin >> scores[18];
					
					if (scores[18]==10)
					{
					cout << "Enter score for frame 10, roll 2: ";
					cin >> scores[19];

					cout << "Enter score for frame 10, roll 3: ";
					cin >> scores[20];
					}
					
					else
					{
					cout << "Enter score for frame 10, roll 2: ";
					cin >> scores[19];
					
					if(scores[18]+scores[19]<10)
					scores[20]=0;
					}

		
				}			
			frame++;
			
		}


//calculate the sum of the totalScores
playerSum=0;
for(int i=0;i<21;i++)
{
playerSum+=totalScore[i];
}	


	}
//End of while loop for scoring
return 0;
}

