#include <iostream>	
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
void PrintIntro();
std::string getValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();
FBullCowGame BCGame;

int main() {
	//introduce the game

	//get a guess from the player
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		PrintGameSummary();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain = true);
	// loop for the number of turns asking for guesses
	return 0;
}

void PrintIntro() {



	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.getHiddenWordLength();
	std::cout << " letter isogram that I am thinking of?\n";
	std::cout << std::endl;
	return;
}

// loop continually until user gives valid guess
FText getValidGuess() { //TODO make valid guess
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText GUESS = "";
	do{
	int32 ctry = BCGame.getCurrentTry();
	std::cout << "Try: " << ctry << "of" << BCGame.getmaxtries() << ". Please enter a word " << std::endl;
	
	std::getline(std::cin, GUESS);
	 Status = BCGame.CheckGuessValidity(GUESS);
	switch (Status) {
	case EGuessStatus::Wrong_Length:
		std::cout << "Please enter a " << BCGame.getHiddenWordLength() << "letter word";
			break;
	case EGuessStatus::Not_Isogram:
		std::cout << "This is not an isogram.\n";
			break;
	case EGuessStatus::Not_Lowercase:
		std::cout << "Please enter all lowercase letters\n";
			break;
	default:
		break;
	}
	std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return GUESS;
}
void PlayGame() {
	BCGame.Reset();
	int32 maxtry = BCGame.getmaxtries();
	//TODO change from FOR to WHILE loop once we are validating tries
	while (!BCGame.isGameWon() && BCGame.getCurrentTry()<=maxtry){
		FText GUESS = getValidGuess(); //TODO make loop checking valid
								  //Submit valid guess to the game
								  //Print number of bulls and cows
	
		
	
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(GUESS);
	std::cout << "Bulls= " << BullCowCount.Bulls;
	std::cout << "Cows = " << BullCowCount.Cows << "\n\n";
 		std::cout << std::endl;
	}
	return;
	//TODO summarise game	
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again?";
	FText response = "";
	getline(std::cin, response);
	std::cout << std::endl;
	return (response[0] == 'y') || (response[0] == 'Y');
}
void PrintGameSummary() {
	
	if (BCGame.isGameWon()) {
		std::cout << "You Won!";
	}
	else {
		std::cout << "You lost...";
	}

	}

