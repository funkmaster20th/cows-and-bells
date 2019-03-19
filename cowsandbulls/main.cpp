/* This si the console executable, that makes us of the BullCow Class
This as the view in a MVC pattern, and is responsible for all
user interaction. For game logix see the FBULLCOWGAME class. 
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// tom make syntax unreal friendly
using FText = std::string;
using int32 = int;

//function prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetGuess();
FText PrintBack(FText Guess);
bool AskToPlayAgain();
void PrintGameSummary();


FBullCowGame BCGame; //instantiate a new game, which we use across plays

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
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetGuess(); 

		
		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		PrintBack(Guess);
		std::cout << std::endl;
	}
	PrintGameSummary();
	return;
}


//introduce the game
void PrintIntro() {
	
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWorldLength() << " letter isogram I'm thinking of?" << std::endl;
	return;
}

//loop continally until the user gives a valid guess
FText GetGuess() {  
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	
	do {
		int32 CurrTries = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrTries << " of " << BCGame.GetMaxTries(); 
		std::cout << ". What is your Guess ? : ";

		

		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidaity(Guess);

		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWorldLength() << " letter word. \n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		default:
			//assuming the guess is valid
			break;
			}
	} while (Status != EGuessStatus::OK);  //keep looping unitil will get guess

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

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE YOU WIN!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}

