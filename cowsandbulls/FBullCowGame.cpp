#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() {
	Reset();
} 

void FBullCowGame::Reset() 
{

	constexpr int32 MAX_TRIES = 5;

	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";

	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;

}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWorldLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidaity(FString Guess) const
{
	if (!IsIogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWorldLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{ 
		return EGuessStatus::OK;
	}
}

//recevies a VALID guess incriments turn, and returns counts

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

		/// set up a return variable
		FBullCowCount BullCowCount;

	//loop throuhg all letters in the hidden word
		int32 WordLength = MyHiddenWord.length(); //assuming the same lenth as guess

		for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
			// compare letters against the hidden word
			for (int32 GChar = 0; GChar < WordLength; GChar++) {
				if (Guess[GChar] == MyHiddenWord[MHWChar])
					if (MHWChar == GChar) {	//if they match increment bulls in there in the same place
						BullCowCount.Bulls++;
					}
					else
				{
					BullCowCount.Cows++; //increment cows if not

				}
		
		
			}
		}
		if (BullCowCount.Bulls == WordLength)
		{
			bGameIsWon = true;
		}
		else {
			bGameIsWon = false;
		};

	return BullCowCount;
}

bool FBullCowGame::IsIogram(FString Word) const
{
	//treat 0 and 1 letter wors as isogram
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter); // handle mixed cases
		
		if (LetterSeen[Letter]) { return false; }// if the letter is in the map we do not have an isogram
		else {
			LetterSeen[Letter] = true;
		}
		
		
		// add the letter to the map as seen
	}
	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) { return false; }// if the letter is lower then flase
		else {
			return true;
		}
	}
	return true;
}

