#include "SoloHangmanGame.h"
#include "InvalidGuess.h"
#include "AlreadyGuessed.h"
#include "MyVector.h"
#include <iostream>
#include <random>
#include <cstdlib>  
#include <ctime>   

using namespace std;

SoloHangmanGame::SoloHangmanGame(Person* p) : player(p), max_tries(6), attempts_left(6) 
{
	word_list.push("apple");
	word_list.push("banana");
	word_list.push("grapes");
	word_list.push("kiwi");
	select_word();
}

void SoloHangmanGame::select_word() 
{
	if (word_list.size() == 0) 
	{
	    return;
	}

	int index;
    index = rand() % word_list.size(); 
	secret_word = word_list[index];
	guessed_word = string(secret_word.length(), '_');
}

bool SoloHangmanGame::check_guess(char guess) 
{
	bool correct = false;
	
	for (int i = 0; i < (int)secret_word.length(); i++) 
	{
		if (secret_word[i] == guess) 
		{
			guessed_word[i] = guess;
			correct = true;
		}
	}
	return correct;
}

void SoloHangmanGame::display_status() 
{
	cout << "Word: " << guessed_word << endl;
	
	cout << "Guessed letters: ";
	
	for (int i = 0; i < (int)guessed_letters.size(); i++) 
	{
		cout << guessed_letters[i] << ' ';
	}
	
	cout << endl;
	cout << "Attempts left: " << attempts_left << endl;
}