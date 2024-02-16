#include <bits/stdc++.h>
using namespace std;

int upperBound(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    vector<int> sortedArray = {1,3, 3, 4, 4, 6, 7, 8, 9, 10};
    int target = 4;

    int index = upperBound(sortedArray, target);

    if (index < sortedArray.size()) {
        cout << "First element greater than " << target << " found at index " << index << '\n';
    } else {
        cout << "No element greater than " << target << " found in the array" << '\n';
    }

    return 0;
}
