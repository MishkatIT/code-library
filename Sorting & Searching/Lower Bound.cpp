#include <bits/stdc++.h>
using namespace std;

int lowerBound(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    vector<int> sortedArray = {1, 2, 4, 4, 4, 6, 7, 8, 9, 10};
    int target = 4;

    int index = lowerBound(sortedArray, target);

    if (index < sortedArray.size()) {
        cout << "First element not less than " << target << " found at index " << index << '\n';
    } else {
        cout << "All elements are less than " << target << " in the array" << '\n';
    }

    return 0;
}
