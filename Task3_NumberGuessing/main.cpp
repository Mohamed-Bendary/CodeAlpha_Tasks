#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

void playGame(int range, int MaxAttempts);

int main() {
    int choice, range, maxAttempts;
    
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Choose a difficulty level:\n";
    cout << "1. Easy (1-50, 10 attempts)\n";
    cout << "2. Medium (1-100, 7 attempts)\n";
    cout << "3. Hard (1-500, 5 attempts)\n\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            range = 50;
            maxAttempts = 10;
            break;
        case 2:
            range = 100;
            maxAttempts = 7;
            break;
        case 3:
            range = 500;
            maxAttempts = 5;
            break;
        default:
            cout << "Invalid choice. Starting game at Medium difficulty.\n";
            range = 100;
            maxAttempts = 7;
    }

    playGame(range, maxAttempts);

    return 0;
}


void playGame(int range, int MaxAttempts) {
    int number, guess, attempts = 0;
  
    /* Generating Random number between 1 and 100 */
    number = rand() % range + 1; 

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have selected a number between 1 and " << range << " , Try to slecet it!\n\n";

    /* Main game loop */
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > (2*number)) 
        {
            cout << "Guess is too high!\n\n";
        } 
        else if ((2*guess) < number)
        {
            cout << "Guess is too low!\n\n";
        } 
        else if (guess > number)
        {
            cout << "Guess is high but close!\n\n"; 
        }
        else if (guess < number)
        {
             cout << "Guess is low but close!\n\n";
        }
        else
        {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts!\n";
        }
    } while (guess != number && attempts <= MaxAttempts);

    if(attempts > MaxAttempts) cout << "Game is over, you reached your Max attempts \n\n";
}