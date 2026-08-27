#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX; // Cheapest Price So Far
    int maxProfit = 0;      // All-Time Best Profit (Starts at 0, protecting us from losses)

    for (int i = 0; i < prices.size(); i++) {
        //  Is today's price the cheapest we've ever seen?
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        
        // If we sold today using our historical cheapest price, is it our best profit?
        int currentProfit = prices[i] - minPrice;
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
        }
    }
    
    return maxProfit;
}

int main() {
    vector<int> droppingPrices = {7, 6, 4, 3, 1};
    cout << "Maximum Profit: " << maxProfit(droppingPrices) << "\n"; 
    return 0;
}