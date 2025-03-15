#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <climits>

using namespace std;

int bestScore = INT_MAX; // Initialize best score to maximum integer value

//Function to play single round of the game
void playGame() {
    srand(time(0));  // Seed random number generator
    int secretNumber = rand() % 100 + 1;  // Generate a number between 1 and 100
    int guess, attempts = 0, maxAttempts;
    char difficulty;
    time_t startTime, endTime;

    // Difficulty selection
    cout << "Choose difficulty: (E)asy (10 attempts) or (H)ard (5 attempts): ";
    cin >> difficulty;
    maxAttempts = (difficulty == 'H' || difficulty == 'h') ? 5 : 10;

    cout << "\n I have chosen a number between 1 and 100. Try to guess it!" << endl;
    cout << "You have " << maxAttempts << " attempts. Good luck!\n" << endl;

    time(&startTime);  // Start the timer
    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input! Please enter a number between 1 and 100." << endl;
            continue;
        }

        attempts++;

        if (guess == secretNumber) {
            time(&endTime);  // Stop the timer
            double timeTaken = difftime(endTime, startTime);  // Calculate time taken

            cout << "Congratulations! You guessed the number in " << attempts << " attempts! 🎉" << endl;
            cout << "Time taken: " << timeTaken << " seconds" << endl;

            // Update best score
            if (attempts < bestScore) {
                bestScore = attempts;
                cout << "New best score! 🏆" << endl;
            } else {
                cout << "Best score: " << bestScore << " attempts" << endl;
            }

            // Player rating
            if (attempts <= 3) cout << "Rating: Excellent! You're a pro!" << endl;
            else if (attempts <= 6) cout << "Rating: Good job!" << endl;
            else cout << "Rating: You did well! Keep practicing!" << endl;
            return;
        } else if (abs(guess - secretNumber) <= 5) {
            cout << "You are very close! Keep going!" << endl;
        } else if (guess > secretNumber) {
            if (guess > 100) {
                cout << "Invalid input! Please enter a number between 1 and 100." << endl;
                continue;
            } else {
                cout << "Too high! Try again." << endl;
            }
        } else {
            if (guess < 0) {
                cout << "Invalid input! Please enter a number between 1 and 100." << endl;
                continue;
            } else {
                cout << "Too low! Try again." << endl;
            }
        }

        cout << "Attempts left: " << (maxAttempts - attempts) << endl;

    } while (attempts < maxAttempts);

    // Losing message
    cout << "\nSorry, you've used all " << maxAttempts << " attempts!" << endl;
    cout << "The secret number was: " << secretNumber << endl;
    cout << "Better luck next time!" << endl;
}

int main() {
    char playAgain;

    do {
        playGame();  // Run the game

        cout << "\nDo you want to play another round? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing! See you next time!" << endl;
    return 0;
}
