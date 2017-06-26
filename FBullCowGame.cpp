#include "FBullCowGame.h"
using int32 = int;
FBullCowGame::FBullCowGame() {
	Reset();
}

void FBullCowGame::Reset() {

	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString Hiddenword = "planet";
	MyHiddenWord = Hiddenword;
	MyCurrentTry = 1;
	bGameIsWon = false;
	
}

int32 FBullCowGame::getmaxtries() const 
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,5},{4,6},{5,7},{6,9} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::getCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::isGameWon() const
{
	return bGameIsWon;
}
//receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	//loop through all letters in the guess
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
	for (int32 GChar = 0; GChar < WordLength; GChar++) {
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}else{
					BullCowCount.Cows++;
			
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else{
		bGameIsWon = false;
	}


	//compare letters against the hidden word
		// if they're in the same place
		//increment bulls 
		//else
		//increment cows if not

	return BullCowCount;

}
int32 FBullCowGame::getHiddenWordLength() const
{
	int32 HWLength = MyHiddenWord.length();
	return HWLength;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto letter : Word) {
		if (!islower(letter)) {
			return false;

		}
		else {
			return true;
		}
	}
}
	
bool FBullCowGame::IsIsogram(FString Word) const
{	
	if (Word.length() <= 1) {

		return true;	
	}
	TMap<char, bool> LetterSeen;
	for (auto letter : Word) {
		letter = tolower(letter);
		if (LetterSeen[letter]) {
			return false;
		}else{
			(LetterSeen[letter] = true);

		}
	}

}
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != getHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}

	}
	 //TODO Make actual error

