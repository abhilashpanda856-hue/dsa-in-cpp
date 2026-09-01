#include <iostream>
#include <vector>
using namespace std;

// THE PARTITION FUNCTION (The Organizer)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last person as the Reference Marker
    int i = low - 1;       // Tracks the boundary of the "shorter" group

    for (int j = low; j < high; j++) {
        // If someone is shorter than the pivot, move them to the left group
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move the Reference Marker into their exact, permanent final position
    swap(arr[i + 1], arr[high]);
    
    return i + 1; // Return the permanent index of the pivot
}

// THE RECURSIVE CONQUEROR (The Manager)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        //  Organize the current group and lock the pivot in place
        int pivotIndex = partition(arr, low, high);

        //  Hand off the left group (shorter students) to be sorted
        quickSort(arr, low, pivotIndex - 1);

        //  Hand off the right group (taller students) to be sorted
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> heights = {6, 3, 9, 5, 2, 8};
    quickSort(heights, 0, heights.size() - 1);
    
    cout << "Sorted array: ";
    for (int num : heights) cout << num << " ";
    cout << "\n";
    return 0;
}
// Quick Sort :- TC -> O(n log n) , TC -> O(n^2) (when array is already sorted or reverse sorted), SC -> O(log n)