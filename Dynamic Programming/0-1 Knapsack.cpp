#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n);
    vector<int> weights(n);

    cout << "Enter the values and weights of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    cout << "Enter the maximum knapsack capacity: ";
    cin >> capacity;

    int result = knapsack(capacity, weights, values, n);
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
