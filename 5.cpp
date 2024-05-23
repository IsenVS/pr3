#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string name;
    int score;
    char class_section; 
};

int main() {
    vector<Student> students = {
        {"Алексей", 90, 'A'},
        {"Мария", 85, 'A'},
        {"Дмитрий", 95, 'B'},
        {"Анна", 88, 'A'},
        {"Сергей", 92, 'B'},
        {"Ольга", 80, 'A'},
        {"Игорь", 78, 'B'},
        {"Елена", 94, 'A'},
        {"Павел", 87, 'B'},
        {"Виктория", 89, 'A'},
        {"Андрей", 91, 'B'}
    };

    vector<Student> class_A, class_B;
    for (const auto& student : students) {
        if (student.class_section == 'A') {
            class_A.push_back(student);
        } else if (student.class_section == 'B') {
            class_B.push_back(student);
        }
    }

    auto compare_scores = [](const Student& a, const Student& b) {
        return a.score > b.score;
    };

    sort(class_A.begin(), class_A.end(), compare_scores);
    sort(class_B.begin(), class_B.end(), compare_scores);

    int N = 3;
    cout << "\nТоп-" << N << " студентов класса A:\n";
    for (int i = 0; i < N && i < class_A.size(); ++i) {
        cout << class_A[i].name << ": " << class_A[i].score << endl;
    }

    cout << "\nТоп-" << N << " студентов класса B:\n";
    for (int i = 0; i < N && i < class_B.size(); ++i) {
        cout << class_B[i].name << ": " << class_B[i].score << endl;
    }

    return 0;
}
