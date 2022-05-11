#pragma once

using namespace std;

const int CONST_HANGMAN_STEPS = 11;
char askLetter();
bool isLetterIn(string& wordToGuess, char guess, string& blankWord);
void hangman(int mistakes);
void displayGuessedLetters(vector<char> guessedLetters);
void playTheGame(string& wordToGuess);