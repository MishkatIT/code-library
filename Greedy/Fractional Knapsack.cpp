#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Comparator to sort items by value per unit weight in descending order
bool cmp(const Item& a, const Item& b)
{
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int capacity, vector<Item>& items)
{
    sort(items.begin(), items.end(), cmp);

    double max_value = 0.0;

    for (const Item& item : items) {
        if (capacity >= item.weight) {
            max_value += item.value;
            capacity -= item.weight;
        } else {
            max_value += (double)item.value * capacity / item.weight;
            break;
        }
    }

    return max_value;
}

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter the values and weights of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter the maximum knapsack capacity: ";
    cin >> capacity;

    double result = fractionalKnapsack(capacity, items);
    cout << "The maximum value that can be obtained is: " << result << endl;

    return 0;
}


/*

3
60 10
100 20
120 30
50

*/
