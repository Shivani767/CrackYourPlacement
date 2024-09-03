#include<bits/stdc++.h>
using namespace std;

// Return true, if reversing the subarray will sort the array, else return false.
bool checkReverse(int arr[], int n) {
    // Create a copy of the original array.
    int temp[n];
    copy(arr, arr + n, temp);

    // Sort the copied array.
    sort(temp, temp + n);

    // Find the first mismatch.
    int front;
    for (front = 0; front < n; front++) {
        if (temp[front] != arr[front]) {
            break;
        }
    }

    // If the whole array is already sorted, return true.
    if (front == n) {
        return true;
    }

    // Find the last mismatch.
    int back;
    for (back = n - 1; back >= 0; back--) {
        if (temp[back] != arr[back]) {
            break;
        }
    }

    // If the subarray is already sorted, return true.
    if (front >= back) {
        return true;
    }

    // Check if the subarray is decreasing or not.
    for (int i = front; i < back; i++) {
        if (arr[i] < arr[i + 1]) {
            return false;
        }
    }

    return true;
}

// Driver Program
int main() {
    int arr[] = {1, 2, 5, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    checkReverse(arr, n) ? (cout << "Yes" << endl) : (cout << "No" << endl);
    return 0;
}
