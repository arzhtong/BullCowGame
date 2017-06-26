#pragma once
#include <string>
#include <map>
#define TMap std::map
using FString = std::string;
using int32 = int;
struct FBullCowCount {
	int32 Cows = 0;
	int32 Bulls = 0;
};
enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

class FBullCowGame {
public:
	FBullCowGame();
	void Reset(); //TODO MAKE A MORE RICH RETURN VALUE.
	int32 getmaxtries() const;
	int32 getCurrentTry() const;
	bool isGameWon() const;
	EGuessStatus CheckGuessValidity(FString Guess) const;//TODO MAKE A MORE RICH RETURN VALUE
									  //provide method for counting bulls and cows and increasing turn #
	FBullCowCount SubmitValidGuess(FString Guess);
	int32 getHiddenWordLength() const;
	
	
private:
	// See constructor for initialization.
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString Word) const;

};