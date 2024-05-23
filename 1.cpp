#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream> 
using namespace std;

struct LiteraryWorks {
    string author;
    string works;
    int year;
};

int main() {
    vector<LiteraryWorks> literaryWorks{
        {"Пушкин", "Медный всадник", 1833},
        {"Чехов", "Спать хочется", 1888},
        {"Пушкин", "Капитанская дочка", 1836},
        {"Жуковский", "Весенние воды", 1832},
        {"Пушкин", "Евгений Онегин", 1823},
        {"Пушкин", "Анджело", 1833},
        {"Жуковский", "Мой друг", 1815},
        {"Чехов", "Ионыч", 1898},
        {"Жуковский", "Нищий", 1824},
        {"Крылов", "Волк на псарне", 1807}
    };

    vector<LiteraryWorks> result;
    copy_if(literaryWorks.begin(), literaryWorks.end(), back_inserter(result), [](const LiteraryWorks& LW) {
        stringstream ss(LW.works);
        string word;
        int wordCount = 0;
        while (ss >> word) {
            ++wordCount;
        }
        return (LW.author == "Пушкин" && wordCount == 2 && LW.year > 1825);
    });

    for (const auto& LW : result) {
        cout << LW.author << " '" << LW.works << "' " << LW.year << endl;
    }

    return 0;
}
