#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

struct Product {
    string name;
    bool on_sale;
};

int main() {
    vector<string> shopping_list = {"Бананы", "Молоко", "Хлеб", "Масло"};
    vector<Product> store_products = {
        {"Яблоки", false}, {"Молоко", true}, {"Хлеб", false}, {"Вода", false},
        {"Помидоры", false}, {"Конфеты", false}, {"Чай", false}
    };
    vector<string> bought_products;
    vector<string> missing_products;

    unordered_map<string, bool> store_map;
    for (const auto& product : store_products) {
        store_map[product.name] = product.on_sale;
    }

    for (const auto& item : shopping_list) {
        auto it = store_map.find(item);
        if (it != store_map.end()) {
            bought_products.push_back(item);
        } else {
            missing_products.push_back(item);
        }
    }

    for (const auto& product : store_products) {
        if (product.on_sale && find(shopping_list.begin(), shopping_list.end(), product.name) == shopping_list.end()) {
            bought_products.push_back(product.name);
        }
    }

    cout << "Список купленных товаров:\n";
    for (const auto& product : bought_products) {
        cout << "- " << product << endl;
    }

    cout << "\nСписок отсутствующих товаров:\n";
    for (const auto& product : missing_products) {
        cout << "- " << product << endl;
    }

    return 0;
}
