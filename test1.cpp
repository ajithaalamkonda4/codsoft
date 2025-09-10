//NUMBER GUESING GAME
#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "===== Number Guessing Game =====" << endl;
    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Can you guess it?" << endl;

    // Game loop
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " 
                 << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}

