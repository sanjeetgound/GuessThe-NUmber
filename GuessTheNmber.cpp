#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_ATTEMPTS = 10;  // Maximum number of attempts allowed
const int LOWER_BOUND = 1;   // Lower bound for the random number
const int UPPER_BOUND = 100; // Upper bound for the random number

int main() {
    int numberToGuess, userGuess;
    int attempts = 0;
    bool isCorrect = false;

    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Generate a random number between LOWER_BOUND and UPPER_BOUND
    numberToGuess = LOWER_BOUND + rand() % (UPPER_BOUND - LOWER_BOUND + 1);

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I have chosen a number between " << LOWER_BOUND << " and " << UPPER_BOUND << ". Can you guess what it is?" << endl;

    // Main game loop
    while (attempts < MAX_ATTEMPTS && !isCorrect) {
        cout << "Attempt " << attempts + 1 << " of " << MAX_ATTEMPTS << ": Enter your guess: ";
        cin >> userGuess;

        // Increment the attempt counter
        attempts++;

        // Check the user's guess
        if (userGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            isCorrect = true;
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    }

    // If the user did not guess correctly within the allowed attempts
    if (!isCorrect) {
        cout << "Sorry, you've used all your attempts. The number was " << numberToGuess << "." << endl;
    }

    return 0;
}
