#include "HumanPlayer.h"
#include "MyVector.h"
#include <iostream>

HumanPlayer::HumanPlayer() : Person(), real_name("Unknown") {}

HumanPlayer::HumanPlayer(const string& uname, const string& rname) : Person(uname), real_name(rname) {}
    
HumanPlayer::HumanPlayer(const HumanPlayer& other) : Person(other), real_name(other.real_name) {}