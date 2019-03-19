#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {

public:
	FBullCowGame(); //the construter 

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWorldLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidaity(FString) const;

	void Reset(); 


	// counts bulls & cows , and increase try # assuming a valid guess
	FBullCowCount SubmitValidGuess(FString);



private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIogram(FString) const; 
	bool IsLowercase(FString) const;
};