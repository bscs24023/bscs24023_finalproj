#ifndef INVALIDGUESS_H
#define INVALIDGUESS_H

class InvalidGuess 
{
    public:
        const char* message() const 
        {
            return "Invalid! Please enter a lowercase letter from a to z.";
        }
};

#endif
