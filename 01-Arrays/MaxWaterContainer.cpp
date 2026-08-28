#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;                  
    int right = height.size() - 1; 
    int maxWater = 0;              // All-Time Max Water

    while (left < right) {
        // Calculate current width and the bottleneck height
        int currentWidth = right - left;
        int currentHeight = min(height[left], height[right]);
        
        // Calculate water for the current setup and update the record if it's the best
        int currentWater = currentWidth * currentHeight;
        maxWater = max(maxWater, currentWater);

        // The Golden Rule: Whoever is holding the shorter side must move
        if (height[left] < height[right]) {
            left++;  // Move the left pointer inward
        } else {
            right--; // Move the right pointer inward
        }
    }

    return maxWater;
}

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Maximum water container area is: " << maxArea(heights) << "\n";
    return 0;
}