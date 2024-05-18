#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0)); // seed the random number generator
    int secretNumber = rand() % 101; // generate a random number between 0 and 100
    int guess;

    std::cout << "Welcome to the guessing game! Guess a number between 0 and 100.\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if(guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else if(guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        }
    } while(guess != secretNumber);

    std::cout << "Congratulations! You guessed the number.\n";

    return 0;
}