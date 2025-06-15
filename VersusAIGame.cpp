#include "VersusAIGame.h"
#include "InvalidGuess.h"
#include "AlreadyGuessed.h"
#include "MyVector.h"
#include <cstdlib>  
#include <ctime>  
#include <iostream>
#include <random>

using namespace std;

VersusAIGame::VersusAIGame(Person* p1, Person* p2) : player1(p1), player2(p2), max_tries(6), attempts1(0), attempts2(0) 
{
    word_list.push("apple");
    word_list.push("banana");
    word_list.push("grapes");
    word_list.push("kiwi");
    select_word();
}

void VersusAIGame::select_word() 
{
    if (word_list.size() == 0) 
    {
        return;
    }

    int index = rand() % word_list.size();
    secret_word = word_list[index];
    guessed_word = string(secret_word.length(), '_');
}

bool VersusAIGame::already_guessed(char c, const MyVector<char>& guesses) 
{
    for (int i = 0; i < (int)guesses.size(); i++) 
    {
        if (guesses[i] == c)
        {
            return true;
        }
    }
    return false;
}

bool VersusAIGame::check_guess(char guess) 
{
    bool correct = false;
    
    for (int i = 0; i < (int)secret_word.length(); i++) 
    {
        if (secret_word[i] == guess) 
        {
            guessed_word[i] = guess;
            correct = true;
        }
    }
    return correct;
}

void VersusAIGame::display_state() 
{
    cout << endl;
    cout << "Guessed word: " << guessed_word << endl;
    
    cout << player1->username << " guessed letters: ";
    
    for (int i = 0; i < (int)guesses1.size(); i++) 
    {
        cout << guesses1[i] << " ";
    }
    
    cout << endl;
    cout << player2->username << " guessed letters: ";
    
    for (int i = 0; i < (int)guesses2.size(); i++) 
    {
        cout << guesses2[i] << " ";
    }
    cout << endl;
}

void VersusAIGame::play() 
{
    cout << "2-player AI game:";
    cout << endl;
    
    player1->displayUser();
    player2->displayUser();

    while (guessed_word != secret_word && (attempts1 < max_tries || attempts2 < max_tries)) 
    {
        display_state();

        if (attempts1 < max_tries) 
        {
            cout << endl;
            cout << player1->username << " Hangman:" << endl;
            drawer.draw(attempts1, max_tries);
            
            try 
            {
                char guess = player1->makeGuess(guessed_word, guesses1);

                if (guess < 'a' || guess > 'z') 
                {
                    throw InvalidGuess();
                }
                
                if (already_guessed(guess, guesses1)) 
                {
                    throw AlreadyGuessed();
                }

                guesses1.push(guess);
                
                if (!check_guess(guess)) 
                {
                    attempts1++;
                }
                
            } 
            
            catch (InvalidGuess& e) 
            {
                cout << e.message() << endl;
            } 
            catch (AlreadyGuessed& e) 
            {
                cout << e.message() << endl;
            }
        }

        if (guessed_word == secret_word) 
        {
            break;
        }
        
        if (attempts2 < max_tries) 
        {
            cout << endl;
            cout << player2->username << " Hangman:" << endl;
            drawer.draw(attempts2, max_tries);
            
            try 
            {
                char guess = player2->makeGuess(guessed_word, guesses2);

                if (guess < 'a' || guess > 'z') 
                {
                    throw InvalidGuess();
                }
                
                if (already_guessed(guess, guesses2)) 
                {
                    throw AlreadyGuessed();
                }

                guesses2.push(guess);
                
                if (!check_guess(guess)) 
                {
                    attempts2++;
                }
                
                
            } 
            
            catch (InvalidGuess& e) 
            {
                cout << "AI Error: " << e.message() << endl;
            } 
            catch (AlreadyGuessed& e) 
            {
                cout << "AI Error: " << e.message() << endl;
            }
        }

        if (guessed_word == secret_word) 
        {
            break;
        }
    }

    cout << endl;
    cout << player1->username << " Final Hangman:" << endl;
    drawer.draw(attempts1, max_tries);
    
    cout << endl;
    cout << player2->username << " Final Hangman:" << endl;
    drawer.draw(attempts2, max_tries);
    

    if (guessed_word == secret_word) 
    {
        if (attempts1 < attempts2)
        {
            cout << player1->username << " wins!" << endl;
        }
        else if (attempts2 < attempts1)
        {
            cout << player2->username << " wins!" << endl;
        }
        else
        {
            cout << "It's a tie!" << endl;
        }
    } 
    
    else 
    {
        cout << "No one guessed the word correctly. Game over." << endl;
    }

    cout << "The secret word was: " << secret_word << endl;
}
