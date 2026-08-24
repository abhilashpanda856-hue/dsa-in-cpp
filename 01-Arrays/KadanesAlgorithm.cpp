#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Casino Analogy
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN; //  All-Time High (starts at lowest possible value)
    int currentSum = 0;   //  Current Streak (money in your pocket)

    for (int i = 0; i < nums.size(); i++) {
        // 1. Play the game: Add the current win/loss to your streak
        currentSum += nums[i]; 

        // 2. Did you break your record? Update All-Time High
        if (currentSum > maxSum) {
            maxSum = currentSum; 
        }

        // 3. Did you go into debt? Cut your losses and reset to 0
        if (currentSum < 0) {
            currentSum = 0; 
        }
    }
    return maxSum;
}
int main(){
    vector<int> arr = {-2,3,2,-1} ;
    cout << "Maximum subarray sum : " << maxSubArray(arr) ;
    return 0;
}