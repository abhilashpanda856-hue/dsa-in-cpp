#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0; // The Frontrunner
    int count = 0;     // The Lead Margin

    for (int i = 0; i < nums.size(); i++) {
        // If the lead margin is 0, the current person becomes the new frontrunner
        if (count == 0) {
            candidate = nums[i];
        }

        // If the current vote is for the frontrunner, increase the lead margin.
        // If it is a vote for anyone else, cancel a vote out (decrease the margin).
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}

int main() {
    vector<int> votes = {2, 2, 1, 1, 1, 2, 2}; // A scattered array
    cout << "The majority element is: " << majorityElement(votes) << "\n";
    return 0;
}