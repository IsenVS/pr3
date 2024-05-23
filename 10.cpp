#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_set>
#include <iterator>
using namespace std;

struct Player {
    string name;
    vector<int> card;
    unordered_set<int> marked;
};

int main() {
    vector<Player> players = {
        {"Игрок 1", {3, 7, 12, 25, 30}},
        {"Игрок 2", {1, 9, 10, 21, 30}},
        {"Игрок 3", {2, 8, 15, 22, 30}}
    };

    vector<int> drawn_numbers = {1, 7, 30, 9, 12, 25, 10, 3, 21, 22, 2, 8, 15};

    for (int num : drawn_numbers) {
        cout << "Ведущий вытянул: " << num << endl;
        for (auto& player : players) {
            if (find(player.card.begin(), player.card.end(), num) != player.card.end()) {
                player.marked.insert(num);
                cout << player.name << " отметил число " << num << endl;
                if (player.marked.size() == player.card.size()) {
                    cout << player.name << " победил, отметив все свои числа!" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Никто не победил." << endl;
    return 0;
}
