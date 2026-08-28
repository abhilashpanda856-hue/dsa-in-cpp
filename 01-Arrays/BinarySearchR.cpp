#include <iostream>
#include <vector>
using namespace std;

// The Recursive Manager Function
int recursiveBinarySearch(vector<int>& nums, int left, int right, int target) {
    // The Base Case (The Stop Sign): No pages left!
    if (left > right) {
        return -1; 
    }

    // Find the exact middle of the current stack
    int mid = left + (right - left) / 2;

    // The Middle Check: Did the current Shinigami get lucky?
    if (nums[mid] == target) {
        return mid; 
    } 
    // Target is smaller: Hand off the left half to the next Shinigami
    else if (nums[mid] > target) {
        return recursiveBinarySearch(nums, left, mid - 1, target); 
    } 
    // Target is bigger: Hand off the right half to the next Shinigami
    else {
        return recursiveBinarySearch(nums, mid + 1, right, target); 
    }
}

int main() {
    vector<int> chapters = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 80;
    
    // starting the delegation with the full stack (index 0 to size - 1)
    int result = recursiveBinarySearch(chapters, 0, chapters.size() - 1, target);
    
    if (result != -1) {
        cout << "Target found at index: " << result << "\n";
    } else {
        cout << "Target not found.\n";
    }
    
    return 0;
}