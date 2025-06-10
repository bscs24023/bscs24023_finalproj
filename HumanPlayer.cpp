#include "HumanPlayer.h"
#include "MyVector.h"
#include "InvalidGuess.h"
#include "AlreadyGuessed.h"
#include <iostream>

HumanPlayer::HumanPlayer() : Person(), real_name("Unknown") {}

HumanPlayer::HumanPlayer(const string& uname, const string& rname) : Person(uname), real_name(rname) {}
    
HumanPlayer::HumanPlayer(const HumanPlayer& other) : Person(other), real_name(other.real_name) {}

void HumanPlayer::displayUser() const 
{
    cout << "Player: " << real_name << endl;
    cout << "Username: " << username << endl;
}

char HumanPlayer::makeGuess(const string& guessedWord, const MyVector<char>& guessedLetters) 
{
    char c;
    cout << "Enter your guess: ";
    cin >> c;
    if (c < 'a' || c > 'z')  
    {
        throw InvalidGuess();
    }
    return c;
}
