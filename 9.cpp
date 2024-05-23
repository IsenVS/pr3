#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
using namespace std;

int main() {
    vector<vector<string>> students_lists = {
        {"Хлеб", "Молоко", "Сок", "Фрукты"},
        {"Сок", "Вода", "Колбаса", "Молоко"},
        {"Хлеб", "Сок", "Шашлык", "Фрукты"}
    };

    vector<string> picnic_wishlist;
    for (const auto& student_list : students_lists) {
        picnic_wishlist.insert(picnic_wishlist.end(), student_list.begin(), student_list.end());
    }
    sort(picnic_wishlist.begin(), picnic_wishlist.end());
    picnic_wishlist.erase(unique(picnic_wishlist.begin(), picnic_wishlist.end()), picnic_wishlist.end());
    cout << "Общий список желаемого на пикник: ";
    for (const auto& product : picnic_wishlist) {
        cout << product << ", ";
    }
    cout << endl;
    return 0;
}
