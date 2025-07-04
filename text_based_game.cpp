#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define RESET   "\033[0m"

class game {
public:
    int level = 1;
    int totalspent = 0;
    int number, round;
    int coin = 100;
    char choice;
    int totalround = 0;
    int lose = 0;
    int tier1 = 0, tier2 = 0, tier3 = 0, tier4 = 0, tier5 = 0;

    void display() {
        cout << YELLOW << "You have initially 100 Coins!\n";
        cout << "RULES:\n";
        cout << GREEN << "Tier 1 - +10 coins\n";
        cout << GREEN << "Tier 2 - +20 coins\n";
        cout << CYAN << "Tier 3 - +30 coins\n";
        cout << CYAN << "Tier 4 - +40 coins\n";
        cout << MAGENTA << "Tier 5 - +50 coins\n";
        cout << RED << "Else -10 coins\n" << RESET;
        cout << WHITE << "Current Player Level: 1\n" << RESET;
    }

    void play() {
        do {
            cout << WHITE << "Available Rounds = " << coin / 10 << RESET << endl;
            cout << WHITE << "Number of times you want to play: " << RESET;
            cin >> round;
            totalround += round;
            cout << endl;

            if (round * 10 > coin) {
                cout << RED << "Insufficient coins!\n" << RESET;
                break;
            }

            cout << CYAN << "Loading";
            for (int i = 0; i < 5; i++) {
                cout << ".";
                Sleep(500);
            }
            cout << "\n\n" << RESET;

            for (int i = 0; i < round; i++) {
                totalspent += 10;
                number = rand() % 100;

                if (number >= 0 && number <= 50) {
                    cout << RED << "Better luck next time!\n-10 Coins :(\n" << RESET;
                    coin -= 10;
                    lose++;
                } else if (number > 50 && number <= 75) {
                    cout << GREEN << "You won Tier 1 gear!\n+10 Coins :)\n" << RESET;
                    coin += 10;
                    tier1++;
                } else if (number > 75 && number <= 90) {
                    cout << GREEN << "You won Tier 2 gear!\n+20 Coins :)\n" << RESET;
                    coin += 20;
                    tier2++;
                } else if (number > 90 && number <= 95) {
                    cout << CYAN << "You won Tier 3 gear!\n+30 Coins :)\n" << RESET;
                    coin += 30;
                    tier3++;
                } else if (number > 95 && number <= 98) {
                    cout << CYAN << "You won Tier 4 gear!\n+40 Coins :)\n" << RESET;
                    coin += 40;
                    tier4++;
                } else {
                    cout << MAGENTA << "You won Tier 5 gear!\n+50 Coins 🔥\n" << RESET;
                    coin += 50;
                    tier5++;
                }

                cout << YELLOW << "Coins: " << coin << "\n\n" << RESET;
                Sleep(500);
            }

            playerlevel();
            cout << WHITE << "Current Level: " << level << "\n" << RESET;

            if (coin > 0) {
                cout << WHITE << "Do you want to continue (Y/N)? " << RESET;
                cin >> choice;
            }

            if (choice == 'N' || choice == 'n') {
                cout << GREEN << "\nThanks for playing!\n" << RESET;
                break;
            }

        } while (coin > 0);
    }

    void playerlevel() {
        if (totalspent >= 10000) level = 5;
        else if (totalspent >= 5000) level = 4;
        else if (totalspent >= 2000) level = 3;
        else if (totalspent >= 1000) level = 2;
    }

    void summary() {
        cout << YELLOW << "\n====== GAME SUMMARY ======\n";
        cout << WHITE << "Total Rounds Played: " << totalround << "\n";
        cout << GREEN << "Total Wins: " << (tier1 + tier2 + tier3 + tier4 + tier5) << "\n";
        cout << GREEN << "Tier 1 Wins: " << tier1 << "\n";
        cout << GREEN << "Tier 2 Wins: " << tier2 << "\n";
        cout << CYAN << "Tier 3 Wins: " << tier3 << "\n";
        cout << CYAN << "Tier 4 Wins: " << tier4 << "\n";
        cout << MAGENTA << "Tier 5 Wins: " << tier5 << "\n";
        cout << RED << "Total Losses: " << lose << "\n";
        cout << YELLOW << "Remaining Coins: " << coin << "\n";
        cout << "Total Coins Spent: " << totalspent << "\n";
        cout << "Final Level Reached: " << level << "\n";
        cout << "===========================\n" << RESET;
    }
};

int main() {
    srand(time(0));
    game g;
    g.display();
    g.play();
    g.summary();
    return 0;
}
