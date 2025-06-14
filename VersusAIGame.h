#ifndef VERSUSAIGAME_H
#define VERSUSAIGAME_H

#include "Person.h"
#include "HangmanDrawer.h"
#include "InvalidGuess.h"
#include "AlreadyGuessed.h"
#include "MyVector.h"
#include <string>

using namespace std;

class VersusAIGame 
{
    private:
        string secret_word;
        string guessed_word;
        MyVector<string> word_list;
        Person* player1;
        Person* player2;
        MyVector<char> guesses1;
        MyVector<char> guesses2;
        int attempts1;
        int attempts2;
        int max_tries;
        HangmanDrawer drawer;

    public:
        VersusAIGame(Person* p1, Person* p2);
        void select_word();
};

#endif