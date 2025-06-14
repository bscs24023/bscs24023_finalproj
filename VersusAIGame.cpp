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