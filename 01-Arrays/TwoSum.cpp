#include <iostream>
#include <vector>
using namespace std;
// Analogy :- when a set of books are arranged in order (from Lowest price to the Highest price)
vector<int> pairSum(vector<int>& nums, int target) {
    int left = 0;                  // Pointer at the cheapest book
    int right = nums.size() - 1;   // Pointer at the most expensive book
    
    while (left < right) {
        int currentSum = nums[left] + nums[right]; // Your Current Bill
        
        if (currentSum == target) {
            // Perfect match! Return the values
            return {nums[left], nums[right]}; 
        } 
        else if (currentSum > target) {
            // Bill is too high (e.g., 60 > 50). Drop the most expensive book.
            right--; 
        } 
        else {
            // Bill is too low (e.g., 40 < 50). Drop the cheapest book.
            left++; 
        }
    }
    
    return {}; // Return empty if no match is found
}

int main() {
    vector<int> books = {10, 20, 30, 40, 50}; // Must be sorted!
    int giftCard = 50;
    
    vector<int> ans = pairSum(books, giftCard);
    
    if (ans.size() == 2) {
        cout << "Books picked: " << ans[0] << " and " << ans[1] << "\n";
    } else {
        cout << "No valid pair found.\n";
    }
    
    return 0;
}