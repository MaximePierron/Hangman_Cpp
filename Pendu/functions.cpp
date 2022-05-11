#include <iostream>
#include <string>
#include "functions.h"
#include <vector>

using namespace std;

char askLetter() {
    cout << "Letter ?" << endl;
    char guess;
    cin >> guess;
    return guess;
}

char toUpper(char guess) {
    if (guess >= 'a' && guess <= 'z') {
        return static_cast<char>(guess + ('A' - 'a'));
    }
    return '-';
}

void displayGuessedLetters(vector<char> guessedLetters) {
    for (char letter: guessedLetters)
    {
        cout << letter << " ";
    }
    cout << "\n";
}

bool isLetterIn(string& wordToGuess, char guess, string& blankWord) {
    bool letterIn = false;
    for (size_t i = 0; i < wordToGuess.length(); i++)
    {
        if (wordToGuess[i] == guess) {
            if (blankWord[i] != guess) {
                blankWord[i] = guess;
            }
            letterIn = true;
        }
    }
    return letterIn;
}

void hangman(int mistakes) {
    cout << endl;
    switch (mistakes) {
    case 11:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |   /|\
                                                    |   / \
                                                    |
                                                  __|__
                )" << endl;
        break;

    case 10:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |   /|\
                                                    |   /
                                                    |
                                                  __|__
                )" << endl;
        break;

    case 9:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |   /|\
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 8:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |   /|
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 7:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 6:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 5:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |
                                                    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 4:
        cout << R"(
                                                    ______
                                                    |/
                                                    |
                                                    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 3:
        cout << R"(
                                                    ______
                                                    |
                                                    |
                                                    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 2:
        cout << R"(

                                                    |
                                                    |
                                                    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 1:
        cout << R"(






                                                  _____
                )" << endl;
        break;
    default:
        cout << endl;
        break;
    }
    cout << endl;
}

void playTheGame(string& wordToGuess) {
    string blankWord = string(wordToGuess.length(), '_');
    int mistakes = 0;
    vector<char> guessedLetters = {};
    while (wordToGuess != blankWord) {
        cout << blankWord << endl;
        cout << "You already proposed: " << endl;
        displayGuessedLetters(guessedLetters);
        char guess = toUpper(askLetter());
        guessedLetters.push_back(guess);
        if (isLetterIn(wordToGuess, guess, blankWord)) {
            cout << "Yay!" << endl;
        }
        else {
            cout << "Nope" << endl;
            mistakes++;
            hangman(mistakes);
        }
        if (blankWord == wordToGuess) {
            cout << "Congrats!" << endl;
        }
        if (mistakes >= CONST_HANGMAN_STEPS) {
            cout << "You lost!" << endl;
            cout << "The word was " << wordToGuess << endl;
            break;
        }
    }
    return;
}