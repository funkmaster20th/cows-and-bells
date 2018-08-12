/* This si the console executable, that makes us of the BullCow Class
This as the view in a MVC pattern, and is responsible for all
user interaction. For game logix see the FBULLCOWGAME class. 
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
FText PrintBack(FText Guess);
bool AskToPlayAgain();


FBullCowGame BCGame; //instantiate a new game

//entry point for application
int main()
{
	bool bResponse = false;
	do {
		PrintIntro();

		PlayGame();

		bResponse = AskToPlayAgain();
		
	} while (bResponse);

	return 0;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	
	//loop for the number fo guess
	// TODO swap from for to while loop once we are validating tires
	for (int32 chances = 1; chances <= MaxTries; chances++) {
		FText Guess = GetGuess(); // TODO make loop ckecking valid
		
		// Submit valid guess to the game

		// Print number of bulls and cows

		PrintBack(Guess);
		std::cout << std::endl;
	}

	// TODO summaris game
}


//introduce the game
void PrintIntro() {

	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	return;
}

//get a guess from the player and print
FText GetGuess() {

	int32 CurrTries = BCGame.GetCurrentTry();

	std::cout <<"Try " << CurrTries << " What is your Guess?:";

	FText Guess = "";

	getline(std::cin, Guess);

	return Guess;
}

FText PrintBack(FText Guess) {

	// repeat the guess back to them

	std::cout << "You guessed " << Guess << std::endl;

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
