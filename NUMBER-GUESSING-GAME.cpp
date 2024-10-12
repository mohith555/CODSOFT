#include <iostream>
#include <cstdlib> 
#include <ctime>  

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    int randomNumber = rand() % 100 + 1; 
    int guess;

    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > randomNumber) {
            cout << "Your guess is too high!" << endl;
        } else if (guess < randomNumber) {
            cout << "Your guess is too low!" << endl;
        } else {
            cout << "Congratulations! You've guessed the number!" << endl;
        }
    } while (guess != randomNumber);

    return 0;
}
