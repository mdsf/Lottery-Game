//A lottery program that generates 5 numbers and asks users to guess them corretly.
//Programmed by Moeid Shariff.

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;


int main()
{
	int winnum[5];
	int user_guess[5];
	char input;
	int counter = 0;
	int sort;

	cout << "*****Welcome to the lottery game****" << endl;
	cout << endl;

	cout << "Input 'y' to play the lottery game and 'n' to exit the game. " << endl;
	cout << endl;
	cin >> input;

	while (input == 'y' || input == 'Y')
	{
		srand(time(0));
		//generates 5 random numbers between 1-40 and saves it in an array.
		for (int i = 0; i < 5; i++)
		{
			winnum[i] = (rand() % 39) + 1;
		}
		cout << endl;

		//sorts the array in ascending order that had 5 random generated numbers
		for (int i = 0; i < 4; i++)//0-4 for an array of size 5 as first index in array is 0
		{
			for (int j = i + 1; j < 5; j++) 
			{
				if (winnum[i] > winnum[j])
				{
					sort = winnum[i]; //first value of array equals to sort
					winnum[i] = winnum[j]; //the elements inside the array switch from left to right
					winnum[j] = sort; //similarly the elements inside the array switch from right to left
				}
			}
		}

		cout << endl;
		cout << "Choose 5 numbers between 1-40: " << endl;
		cout << endl;
		for (int i = 0; i < 5; i++)
		{
			cin >> user_guess[i];
		}
		cout << endl;
		
		//matches the array randomly generated with users response to determine if the guess was correct
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
				if (user_guess[i] == winnum[j])
					counter++;		
		}
		//If the guess is correct for all 5 numbers displays the win message
		switch (counter)
		{
		case 5:
			cout << "You Win!" << endl << endl;
			break;
		default:
			cout << "You Lose!" << endl;//if the guess is wrong it displays the lose message
			cout << endl;
			cout << "The winning numbers are: " << endl;
			cout << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << winnum[i] << " ";//outputs the sorted array values in ascending order
			}
			cout << endl;
			break;		
		}
		cout << endl;
		//prompts the user if he/she wishes to continue playing the game.
		cout << "Would you like to continue 'y' or 'n' " << endl;
	    cin >> input;
	    cout << endl;
	}
	return 0;
}