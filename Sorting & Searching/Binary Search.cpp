#include<bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;                 // Target found at index mid
        } else if (arr[mid] < target) {
            low = mid + 1;              // Target is in the right half
        } else {
            high = mid - 1;             // Target is in the left half
        }
    }

    return -1;                          // Target not found
}

int main() {
    vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 2;

    int result = binarySearch(sortedArray, target);

    if (result != -1) {
        cout << "Target " << target << " found at index " << result << '\n';
    } else {
        cout << "Target " << target << " not found in the array" << '\n';
    }

    return 0;
}
