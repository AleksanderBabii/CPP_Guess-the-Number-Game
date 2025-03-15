#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));  // Seed the random number generator
    int secretNumber = rand() % 100 + 1;  // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;
    int maxAttempts = 7;  // Limit the number of attempts

    cout << "🎮 Welcome to Guess the Number! 🎮" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it!" << endl;
    cout << "You have " << maxAttempts << " attempts. Good luck!\n" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
			cout << "📉 Too high! Try again." << endl;  // Check if the guess is higher than the secret number3
        }
        else if (guess < secretNumber) {
			cout << "📈 Too low! Try again." << endl; // Check if the guess is lower than the secret number
        }
        else if (abs(guess - secretNumber) <= 5) {  
            cout << "🔥 You are very close! Keep going!" << endl; // Check if the guess is within 5 of the secret number
        }
        else {
            cout << "🎉 Congratulations! You guessed the number in " << attempts << " attempts! 🎉" << endl;
            return 0;  // Exit the program when guessed correctly
        }

        cout << "Attempts left: " << (maxAttempts - attempts) << endl;

    } while (guess != secretNumber && attempts < maxAttempts);  // Stop after maxAttempts

    // If the player fails to guess within the max attempts
    cout << "\n😢 Sorry, you've used all " << maxAttempts << " attempts!" << endl;
    cout << "The secret number was: " << secretNumber << endl;
    cout << "Better luck next time! 🎲" << endl;


	return 0;
}


