#include "HangmanDrawer.h"
#include <iostream>

using namespace std;

void HangmanDrawer::draw(int wrong_attempts, int max_tries) 
{
    cout << "Hangman:" << endl;
    cout << wrong_attempts << "/" << max_tries << endl;

    if (wrong_attempts == 0) 
    {
        cout << endl << endl << endl << endl;
    } 
    else if (wrong_attempts == 1) 
    {
        cout << "  O" << endl << endl << endl;
    } 
    else if (wrong_attempts == 2) 
    {
        cout << "  O" << endl << "  |" << endl << endl;
    } 
    else if (wrong_attempts == 3) 
    {
        cout << "  O" << endl << " /|" << endl << endl;
    } 
    else if (wrong_attempts == 4) 
    {
        cout << "  O" << endl << " /|\\" << endl << endl;
    } 
    else if (wrong_attempts == 5) 
    {
        cout << "  O" << endl << " /|\\" << endl << " /" << endl;
    } 
    else if (wrong_attempts == 6) 
    {
        cout << "  O" << endl << " /|\\" << endl << " / \\" << endl;
    } 
    else 
    {
        cout << "Game Over" << endl;
    }

}
