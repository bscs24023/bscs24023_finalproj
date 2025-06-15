#include <iostream>
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "SoloHangmanGame.h"
#include "VersusAIGame.h"

using namespace std;

int main() 
{
    srand(time(0));
    int choice;
    string user_name;
    string real_name;

    cout << "Hangman game: " << endl;
    cout << "Choose a game!: " << endl;
    cout << "1. Single player" << endl;
    cout << "2. Play against AI" << endl;
    cout << "Enter your choice: ";

    cin >> choice;

    cout << "Enter username: ";
    cin >> user_name;
    cout << "Enter real name: ";
    cin >> real_name;

    HumanPlayer* user = new HumanPlayer(user_name, real_name);

    if (choice == 1) 
    {
        SoloHangmanGame solo(user);
        solo.play();
        delete user;
    } 
    else 
    {
        AIPlayer* ai = new AIPlayer();
        VersusAIGame game(user, ai);
        game.play();
        delete ai;
        delete user;
    }
    
    return 0;
}