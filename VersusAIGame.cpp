#include "VersusAIGame.h"
#include "InvalidGuess.h"
#include "AlreadyGuessed.h"
#include "MyVector.h"
#include <cstdlib>  
#include <ctime>  
#include <iostream>
#include <random>

using namespace std;

VersusAIGame::VersusAIGame(Person* p1, Person* p2) : player1(p1), player2(p2), max_tries(6), attempts1(0), attempts2(0) 
{
    word_list.push("apple");
    word_list.push("banana");
    word_list.push("grapes");
    word_list.push("kiwi");
    select_word();
}

void VersusAIGame::select_word() 
{
    if (word_list.size() == 0) 
    {
        return;
    }

    int index = rand() % word_list.size();
    secret_word = word_list[index];
    guessed_word = string(secret_word.length(), '_');
}

bool VersusAIGame::already_guessed(char c, const MyVector<char>& guesses) 
{
    for (int i = 0; i < (int)guesses.size(); i++) 
    {
        if (guesses[i] == c)
        {
            return true;
        }
    }
    return false;
}

bool VersusAIGame::check_guess(char guess) 
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

void VersusAIGame::display_state() 
{
    cout << endl;
    cout << "Guessed word: " << guessed_word << endl;
    
    cout << player1->username << " guessed letters: ";
    
    for (int i = 0; i < (int)guesses1.size(); i++) 
    {
        cout << guesses1[i] << " ";
    }
    
    cout << endl;
    cout << player2->username << " guessed letters: ";
    
    for (int i = 0; i < (int)guesses2.size(); i++) 
    {
        cout << guesses2[i] << " ";
    }
    cout << endl;
}