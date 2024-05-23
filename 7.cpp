#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Person {
    string name;
    string phrase;
};

int main() {
    vector<Person> players = {
        {"Анна", "Привет, как дела"},
        {"Иван", "Привет, как дела"},
        {"Мария", "Привет, как дела"},
        {"Петр", "Привет, как дела"},
        {"Ольга", "Привет, как дела"}
    };

    auto it = find_if(players.begin(), players.end(), [&](const Person& p) {
        return p.phrase != players.front().phrase;
    });

    if (it != players.end()) {
        cout << "Человек, который сделал ошибку: " << it->name << endl;
        cout << "Исходное слово: " << players.front().phrase << endl;
        cout << "Сказанное ошибочное: " << it->phrase << endl;
    } else {
        cout << "Ошибок не найдено. Каждый передал фразу без изменений." << endl;
    }

    return 0;
}
