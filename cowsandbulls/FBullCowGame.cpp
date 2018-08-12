#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() {
	Reset();
} 

void FBullCowGame::Reset() 
{

	constexpr int32 MAX_TRIES = 5;

	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	
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

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidaity(FString)
{
	return false;
}

//recevies a VALID guess incriments turn, and returns 