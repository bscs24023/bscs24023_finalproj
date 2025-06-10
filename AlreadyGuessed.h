#ifndef ALREADYGUESSED_H
#define ALREADYGUESSED_H

class AlreadyGuessed 
{
    public:
        const char* message() const 
        {
            return "You've already guessed this letter.";
        }
};

#endif
