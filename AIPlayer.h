#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Person.h"
#include "MyVector.h"

class AIPlayer : public Person 
{
    private:
        string ai_letters;
        int index;

    public:
        AIPlayer();
        void displayUser() const override;
        char makeGuess(const string& guessedWord, const MyVector<char>& guessedLetters) override;
    
};

#endif
