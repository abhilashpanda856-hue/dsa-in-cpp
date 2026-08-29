#include <iostream>
#include <vector>
using namespace std;

int searchRotatedArray(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Did we land exactly on the target?
        if (nums[mid] == target) {
            return mid; 
        }

        // Is the Left half the perfectly sorted one?
        if (nums[left] <= nums[mid]) {
            // Target Bounds Check: Does the target live inside this left half?
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Throw away the right side
            } else {
                left = mid + 1;  // Throw away the left side
            }
        } 
        //  Otherwise, the Right half MUST be perfectly sorted (Your exact scenario!)
        else {
            // Target Bounds Check: Does the target live inside this right half?
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Throw away the left side
            } else {
                right = mid - 1; // Throw away the right side (Your exact move!)
            }
        }
    }
    
    return -1; // Target not found
}

int main() {
    vector<int> deck = {7, 8, 9, 1, 2, 3, 4};
    int target = 8;
    
    int result = searchRotatedArray(deck, target);
    
    if (result != -1) {
        cout << "Target found at index: " << result << "\n";
    } else {
        cout << "Target not found.\n";
    }
    
    return 0;
}