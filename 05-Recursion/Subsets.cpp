#include <iostream>
#include <vector>
using namespace std;

// The Recursive Decision Tree
void generateSubsets(int index, vector<int>& nums, vector<int>& currentPath, vector<vector<int>>& masterList) {
    // The Base Case (End of the shop)
    if (index == nums.size()) {
        masterList.push_back(currentPath); // Save this timeline's final loadout
        return;
    }

    // The INCLUDE Branch (Buy the item)
    currentPath.push_back(nums[index]);
    generateSubsets(index + 1, nums, currentPath, masterList);

    // The BACKTRACKING Step (Undo the purchase)
    currentPath.pop_back();

    // The EXCLUDE Branch (Skip the item)
    generateSubsets(index + 1, nums, currentPath, masterList);
}

int main() {
    vector<int> shopItems = {1, 2, 3};
    vector<vector<int>> allSubsets;
    vector<int> startingPath;

    generateSubsets(0, shopItems, startingPath, allSubsets);

    cout << "All Possible Loadouts:\n";
    for (const auto& subset : allSubsets) {
        cout << "[ ";
        for (int item : subset) {
            cout << item << " ";
        }
        cout << "]\n";
    }

    return 0;
}