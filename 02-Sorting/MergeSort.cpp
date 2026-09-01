#include <iostream>
#include <vector>
using namespace std;

// THE MERGER (Conquer Phase)
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp; // new combined pile on the table
    int left = low;   // Top card of your left pile
    int right = mid + 1; // Top card of your right pile

    // Compare the top cards until one hand is completely empty
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++; // pulled from the left, so look at the next left card
        } else {
            temp.push_back(arr[right]);
            right++; // pulled from the right, so look at the next right card
        }
    }

    //  If your right hand is empty but your left still has cards, drop them all down
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If your left hand is empty but your right still has cards, drop them all down
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // ransfer the perfectly sorted temporary pile back to the original stack
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// THE SPLITTER (Divide Phase)
void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return; // Base Case: A pile of 1 card is already sorted!

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);      // Split the left half
    mergeSort(arr, mid + 1, high); // Split the right half
    merge(arr, low, mid, high);    // Stitch them back together
}

int main() {
    vector<int> grades = {6, 3, 9, 5, 2, 8};
    mergeSort(grades, 0, grades.size() - 1);
    
    cout << "Sorted array: ";
    for (int num : grades) cout << num << " ";
    return 0;
}
// Merge Sort :- TC -> O(n log n), SC -> O(n)