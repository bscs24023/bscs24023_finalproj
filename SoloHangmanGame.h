#ifndef SOLOHANGMANGAME_H
#define SOLOHANGMANGAME_H

#include "Person.h"
#include "HangmanDrawer.h"
#include "InvalidGuess.h"
#include "AlreadyGuessed.h"
#include "MyVector.h"
#include <string>
using namespace std;

class SoloHangmanGame 
{
    private:
        string secret_word;
        string guessed_word;
        MyVector<char> guessed_letters;
        MyVector<string> word_list;
        int max_tries;
        int attempts_left;
        Person* player;
        HangmanDrawer drawer;
    
    
    public:
        SoloHangmanGame(Person* p);
        void select_word();
        bool check_guess(char guess);
        void display_status();
        bool already_guessed(char c);   
        void play();
};

#endif