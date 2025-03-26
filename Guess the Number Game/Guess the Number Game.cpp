#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <cmath>    // For abs()
#include <limits>   // For clearing input buffer

using namespace std;

// Function to display the welcome message
void displayWelcomeMessage() {
    cout << "\n Welcome to the Guess the Number Game! " << endl;
    cout << "Choose a difficulty level:" << endl;
    cout << "1. Easy (1-50)" << endl;
    cout << "2. Medium (1-100)" << endl;
    cout << "3. Hard (1-500)" << endl;
}

// Function to get difficulty level from the user
int getDifficultyLevel() {
    int choice, maxNumber;
    while (true) {
        cout << "Select (1, 2, or 3): ";
        cin >> choice;

        if (choice == 1) {
            maxNumber = 50;
            break;
        }
        else if (choice == 2) {
            maxNumber = 100;
            break;
        }
        else if (choice == 3) {
            maxNumber = 500;
            break;
        }
        else {
            cout << " Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }
    return maxNumber;
}

// Function to get user's guess
int getUserGuess() {
    int guess;
    cout << "\nEnter your guess: ";
    cin >> guess;
    return guess;
}

// Function to check the guess and give hints
bool checkGuess(int guess, int secretNumber) {
    if (guess == secretNumber) {
        cout << " Congratulations! You guessed the correct number!" << endl;
        return true;
    }
    else if (abs(guess - secretNumber) <= 5) {
        cout << " Very Close! Try again." << endl;
    }
    else if (guess > secretNumber) {
        cout << " Too High! Try again." << endl;
    }
    else {
        cout << " Too Low! Try again." << endl;
    }
    return false;
}

int main() {
    srand(time(0));  // Initialize random seed
    int bestScore = INT_MAX; // Track best (lowest) attempts

    while (true) { // Loop to allow replay
        displayWelcomeMessage(); // Show game instructions
        int maxNumber = getDifficultyLevel(); // Get difficulty level
        int secretNumber = rand() % maxNumber + 1; // Generate number
        int userGuess, attempts = 0;

        cout << "\nI've picked a number between 1 and " << maxNumber << ". Try to guess it!" << endl;

        while (true) {
            userGuess = getUserGuess();
            attempts++;

            if (checkGuess(userGuess, secretNumber)) {
                cout << " You guessed it in " << attempts << " attempts!" << endl;

                // Update best score if necessary
                if (attempts < bestScore) {
                    bestScore = attempts;
                    cout << " New Best Score: " << bestScore << " attempts!" << endl;
                }
                else {
                    cout << "Your best score remains: " << bestScore << " attempts!" << endl;
                }
                break; // Exit guessing loop
            }
        }

        // Ask if the user wants to play again
        char playAgain;
        cout << "\n Do you want to play again? (Y/N): ";
        cin >> playAgain;
        if (playAgain == 'N' || playAgain == 'n') {
            cout << " Thanks for playing! See you next time! 🎮" << endl;
            break; // Exit game loop
        }
    }
    return 0;
}
