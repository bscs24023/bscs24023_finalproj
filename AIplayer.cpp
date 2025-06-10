#include "AIPlayer.h"
#include "MyVector.h"
#include <iostream>

using namespace std;

AIPlayer::AIPlayer() : Person("ai_player"), ai_letters("aeiouchkjbwdlfnt"), index(0) {}

void AIPlayer::displayUser() const 
{
    cout << "AI Player: " << username << endl;
}

char AIPlayer::makeGuess(const string& guessedWord, const MyVector<char>& guessedLetters) 
{
    while (index < (int)ai_letters.length()) 
    {
        char guess = ai_letters[index];
        index++;
        
        bool already_guessed = false;

        for (int i = 0; i < (int)guessedLetters.size(); i++) 
        {
            if (guessedLetters[i] == guess) 
            {
                already_guessed = true;
                break;
            }
        }

        if (!already_guessed) 
        {
            cout << "AI guesses: " << guess << endl;
            return guess;
        }
    }
    
    return ' ';
}