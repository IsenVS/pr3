#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<string> dorm_students = {
        "Рудько",
        "Кирикович",
        "Олейник",
        "Соболев"
    };

    vector<string> domestic_students = {
        "Кравченко",
        "Якуткина",
        "Краснятов",
        "Толстов"
    };

    vector<string> all_students;
    all_students.reserve(dorm_students.size() + domestic_students.size());

    merge(dorm_students.begin(), dorm_students.end(),
               domestic_students.begin(), domestic_students.end(),
               back_inserter(all_students));

    all_students.erase(remove(all_students.begin(), all_students.end(), "Соболев"), all_students.end());

    sort(all_students.begin(), all_students.end());

    cout << "Отсортированный список:\n";
    int count = 1;
        for (const auto& student : all_students) {
            cout << count << ". " << student << endl;
            count++;
    }
    return 0;
}