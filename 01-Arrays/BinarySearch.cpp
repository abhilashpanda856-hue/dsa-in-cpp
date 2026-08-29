#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        // Find the exact middle of our current search space
        int mid = left + (right - left) / 2;

        // Did we land exactly on the target?
        if (nums[mid] == target) {
            return mid; 
        } 
        // The value is too small, target must be in the right half (Your intuition!)
        else if (nums[mid] < target) {
            left = mid + 1; 
        } 
        // The value is too big, target must be in the left half
        else {
            right = mid - 1; 
        }
    }
    
    return -1; // The target is missing
}

int main() {
    vector<int> chapters = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 80;
    
    int result = binarySearch(chapters, target);
    
    if (result != -1) {
        cout << "Target found at index: " << result << "\n";
    } else {
        cout << "Target not found.\n";
    }
    
    return 0;
}