#include<iostream>
#include<vector>
using namespace std;
// Partition function
int part(vector<int>& arr, int lo, int hi) {
    int pvt = arr[lo];
    int i = lo;
    int j = hi;
    while (i < j) {
        while (arr[i] <= pvt && i <= hi - 1) {
            i++;
        }
        while (arr[j] > pvt && j >= lo + 1) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[lo], arr[j]); // Place pivot at correct position
    return j; // Return pivot index
}
// Quick sort function
void qs(vector<int>& arr, int lo, int hi) {
    if (lo < hi) {
        int p_IDX = part(arr, lo, hi);
        qs(arr, lo, p_IDX - 1);
        qs(arr, p_IDX + 1, hi);
    }
}
// Main function
int main() {
    vector<int> arr = {8, 3, 1, 7, 0, 10, 2};
    // Print unsorted array
    cout << "Unsorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    // Sort array
    qs(arr, 0, arr.size() - 1);
    // Print sorted array
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
