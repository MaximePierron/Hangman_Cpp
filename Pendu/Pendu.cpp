#include <iostream>
#include <string>
#include <random>
#include "functions.h"

#include "possiblesWords.h"

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, POSSIBLE_WORDS_SIZE - 1);

    string wordToGuess = possibleWords[distrib(gen)];

    playTheGame(wordToGuess);
}