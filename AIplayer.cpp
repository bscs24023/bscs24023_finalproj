#include "AIPlayer.h"
#include "MyVector.h"
#include <iostream>

using namespace std;

AIPlayer::AIPlayer() : Person("ai_player"), ai_letters("aeiouchkjbwdlfnt"), index(0) {}
