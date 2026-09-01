#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;

    // The Strategic Starting Point: Top-Right Corner
    int row = 0;
    int col = matrix[0].size() - 1; 

    // Keep searching as long as we haven't walked off the grid
    while (row < matrix.size() && col >= 0) {
        
        if (matrix[row][col] == target) {
            return true; // Target found!
        }
        else if (matrix[row][col] > target) {
            col--; // Walk Left for lower clearance
        }
        else {
            row++; // Walk Down for higher clearance
        }
    }
    
    // We walked entirely off the grid without finding the target
    return false; 
}

int main() {
    // A sample matrix where rows and columns are sorted
    vector<vector<int>> vault = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    
    int target = 100; // A target completely missing from the matrix
    
    cout << "Searching for " << target << "...\n";
    if (searchMatrix(vault, target)) {
        cout << "Result: Target Found!\n";
    } else {
        cout << "Result: Target Not Found.\n";
    }
    
    return 0;
}