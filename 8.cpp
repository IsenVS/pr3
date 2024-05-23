#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    vector<string> words = {"applen", "banana", "orange"};
    string common_letters;
    if (!words.empty()) {
        unordered_set<char> common_letters_set(words.front().begin(), words.front().end());
        for (auto it = words.begin() + 1; it != words.end(); ++it) {
            unordered_set<char> current_letters_set(it->begin(), it->end());
            unordered_set<char> new_common_letters_set;
            for (char letter : current_letters_set) {
                if (common_letters_set.count(letter)) {
                    new_common_letters_set.insert(letter);
                }
            }
            common_letters_set = new_common_letters_set;
        }

        for (char letter : common_letters_set) {
            common_letters += letter;
            common_letters += ' '; 
        }
        if (!common_letters.empty()) {
            common_letters.pop_back();
        }
    }
    cout << "Общие буквы: " << common_letters << endl;
    return 0;
}
