#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Person.h"
#include "MyVector.h"
#include "InvalidGuess.h"
#include "AlreadyGuessed.h"

class HumanPlayer : public Person 
{
    private:
        string real_name;

    public:
        HumanPlayer();
        HumanPlayer(const string& uname, const string& rname);
        HumanPlayer(const HumanPlayer& other);

        void displayUser() const override;
        char makeGuess(const string& guessedWord, const MyVector<char>& guessedLetters) override;
    
};

#endif
