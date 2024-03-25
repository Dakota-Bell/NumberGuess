/*

Author: Dakota Bell
Description: Game will use random numbers decided each round. They 
			 will determind what the max number will be and will
			 decide a number between 0 and the random number. The
			 first and second player will get 6 lives each. When 
			 the person who's guess is closest to the random number 
			 will not lose a life, but the other player will. in
			 the event of a tie, neither player will lose a life
Date: 05/19/2023

*/

#include <iostream>
// includes random and srand for random numbas
#include <time.h>
#include <stdlib.h>
using namespace std;

// DECLARATIONS
bool CheckUserGuess(int lives, int numberToGuess, int guess);

// DRIVER
int main(){
	// var for two players 
	int oneLives = 6;
	int twoLives = 6; // <---- will check back later
	// makes a random number to use 
	int numberToGuess = 0;
	srand(time(0)); 
	// Randomizes the numberToGuess
	numberToGuess = rand() % 10;
	
	int guess;
	cout << "\t\t Player One:\n ";
	int userGuess = CheckUserGuess(oneLives, numberToGuess, guess);
	numberToGuess = rand() % 10;
	cout << "\t\t Player Two:\n ";
	userGuess = CheckUserGuess(twoLives, numberToGuess, guess);
	cout << "\nThe correct num: " << numberToGuess << endl;
	
	return 0;
}

// DEFINITIONS
bool CheckUserGuess(int lives, int numberToGuess, int userGuess){
	// If the user still has lives, let them play
	while (lives > 0){
		cout << "Enter your guess for the randomly generated number [0..10]: ";
		// give user the chance to enter their guess
		cin >> userGuess;
		/* if the number is not correct AND if the number is less than the
		   number to guess it will tell you you're guess is too high*/
		if (userGuess != numberToGuess && userGuess > numberToGuess){
			lives--;
			cout << "Incorrect, the number is too high so guess again!\n\nGuesses left: " << lives << endl;
		}
		/* if the number is not correct AND if the number is less than the
		   number to guess it will tell you you're guess is too low*/
		else if (userGuess != numberToGuess && userGuess < numberToGuess){
			lives--;
			cout << "Incorrect, the number is too low so guess again!\n\nGuesses left: " << lives << endl;
		}
		else{
			cout << "\nCongratulations! You guessed the number correctly:)" << endl << endl;
			return true;
		}
	}
	return true;
}
