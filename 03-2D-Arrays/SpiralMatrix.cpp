#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;

    int topRow = 0;
    int bottomRow = matrix.size() - 1;
    int leftCol = 0;
    int rightCol = matrix[0].size() - 1;

    // Keep clearing as long as boundaries haven't crossed
    while (topRow <= bottomRow && leftCol <= rightCol) {
        
        //  Left-to-Right across the top wall
        for (int j = leftCol; j <= rightCol; j++) {
            result.push_back(matrix[topRow][j]);
        }
        topRow++; // Squeeze the top boundary downward

        //  Top-to-Bottom down the right wall
        for (int i = topRow; i <= bottomRow; i++) {
            result.push_back(matrix[i][rightCol]);
        }
        rightCol--; // Squeeze the right boundary inward

        //  Right-to-Left across the bottom wall (WITH SAFETY CHECK)
        if (topRow <= bottomRow) {
            for (int j = rightCol; j >= leftCol; j--) {
                result.push_back(matrix[bottomRow][j]);
            }
            bottomRow--; // Squeeze the bottom boundary upward
        }

        //  Bottom-to-Top up the left wall (WITH SAFETY CHECK)
        if (leftCol <= rightCol) {
            for (int i = bottomRow; i >= topRow; i--) {
                result.push_back(matrix[i][leftCol]);
            }
            leftCol++; // Squeeze the left boundary inward
        }
    }

    return result;
}

int main() {
    vector<vector<int>> dungeon = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    vector<int> clearedPath = spiralOrder(dungeon);
    cout << "Cleared path: ";
    for (int num : clearedPath) cout << num << " ";
    return 0;
}