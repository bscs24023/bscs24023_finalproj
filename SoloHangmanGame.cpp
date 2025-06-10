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

bool SoloHangmanGame::already_guessed(char c) 
{
    
	for (int i = 0; i < (int)guessed_letters.size(); i++) 
	{
		if (guessed_letters[i] == c) 
		{
		    return true;
		}
	}
	return false;
}

void SoloHangmanGame::play() 
{
	cout << "One-player game:";
	
	player->displayUser();

	while (attempts_left > 0 && guessed_word != secret_word) 
	{
        int wrong_attempts = max_tries - attempts_left ;
		drawer.draw(wrong_attempts, max_tries);
		
		display_status();

		try 
		{
			char guess = player->makeGuess(guessed_word, guessed_letters);

			if (guess < 'a' || guess > 'z') 
			{
				throw InvalidGuess();
			}

			if (already_guessed(guess)) 
			{
				throw AlreadyGuessed();
			}

			guessed_letters.push(guess);

			if (!check_guess(guess)) 
			{
				attempts_left--;
				cout << "Wrong guess!" << endl;
			} 
			else 
			{
				cout << "Correct guess!" << endl;
			}

		} 
		
		catch (InvalidGuess& e) 
		{
			cout << e.message() << endl;
		
		} 
		
		catch (AlreadyGuessed& e) 
		{
			cout << e.message() << endl;
		}
	}
    
    cout << "Your hangman: " << endl;
    
	int wrong_attempts2 = max_tries - attempts_left;
	drawer.draw(wrong_attempts2, max_tries);
	
	if (guessed_word == secret_word) 
	{
		cout << "Congratulations! You guessed the word: " << secret_word << endl;
	} 
	else 
	{
		cout << "You lost. The word was: " << secret_word << endl;
	}
}

