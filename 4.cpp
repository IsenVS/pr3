#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

using namespace std;

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {3, 1, -4, 2, 8, 1, -4, 7, 6, 2};

    sort(numbers.begin(), numbers.end());
    cout << "Список чисел в порядке возрастания: ";
    printVector(numbers);

    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Сумма всех чисел: " << sum << endl;

    double average = static_cast<double>(sum) / numbers.size();
    cout << "Среднее значение чисел: " << average << endl;

    cout << "Максимальное число: " << numbers.back() << endl;
    cout << "Минимальное число: " << numbers.front() << endl;

    int negativeCount = count_if(numbers.begin(), numbers.end(), [](int num) {
        return num < 0;
    });
    cout << "Количество отрицательных чисел: " << negativeCount << endl;

    unordered_set<int> uniqueNumbers(numbers.begin(), numbers.end());
    vector<int> uniqueVec(uniqueNumbers.begin(), uniqueNumbers.end());
    cout << "Список без повторяющихся чисел: ";
    printVector(uniqueVec);

    return 0;
}
