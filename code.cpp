#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>
using namespace std;

class Game {
public:
    Game() {
        choices[1] = "rock";
        choices[2] = "paper";
        choices[3] = "scissor";
    }

    void play() {
        int userChoice = getUserChoice();
        int cpuChoice = getRandomChoice();

        cout << "CPU chose " << choices[cpuChoice] << endl;

        determineWinner(userChoice, cpuChoice);
    }

private:
    map<int, string> choices;

    int getUserChoice() const {
        int choice;
        cout << "Enter your choice:\n 1.Rock\n 2.Paper\n 3.Scissor" << endl;
        cin >> choice;
        return choice;
    }

    int getRandomChoice() const {
        srand(static_cast<unsigned int>(time(nullptr)));
        return rand() % 3 + 1;
    }

    void determineWinner(int userChoice, int cpuChoice) const {
        if (userChoice == cpuChoice) {
            cout << "Tie" << endl;
        }
        else if ((userChoice == 1 && cpuChoice == 3) ||
            (userChoice == 2 && cpuChoice == 1) ||
            (userChoice == 3 && cpuChoice == 2)) {
            cout << "You Win" << endl;
        }
        else {
            cout << "CPU Win" << endl;
        }
    }
};

int main() {
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        Game game;
        game.play();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing!" << endl;
        }
    }

    return 0;
}
