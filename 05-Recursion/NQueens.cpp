#include <iostream>
#include <vector>
#include <string>
using namespace std;

// THE SAFETY INSPECTOR
bool isSafe(int row, int col, vector<string>& board, int n) {
    //  Vertical Scan (Straight Up)
    // Keep the column the same, but walk the row backwards to 0
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 'Q') {
            return false; // Jammed!
        }
    }

    //  Left Diagonal Scan (Up and Left)
    // Walk the row backwards AND the column backwards
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false; // Jammed!
        }
    }

    //  Right Diagonal Scan (Up and Right)
    // Walk the row backwards, but the column forwards
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false; // Jammed!
        }
    }

    return true; // All clear!
}

// THE RECURSIVE BACKTRACKER
void solveNQueens(int row, int n, vector<string>& board, vector<vector<string>>& masterList) {
    // Base Case: We successfully placed a camera in every row!
    if (row == n) {
        masterList.push_back(board);
        return;
    }

    // Try placing a camera in every single column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            
            // 1. The INCLUDE Branch (Lock the camera in)
            board[row][col] = 'Q';
            
            // 2. Move down to the next row (Pause current timeline)
            solveNQueens(row + 1, n, board, masterList);
            
            // 3. The BACKTRACKING Step (Undo the installation)
            // If the timeline failed, take the camera off the ceiling
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 4; // A 4x4 grid
    vector<vector<string>> allConfigurations;
    
    // Create an empty N x N board filled with '.'
    vector<string> emptyBoard(n, string(n, '.'));

    // Start the installation at Row 0
    solveNQueens(0, n, emptyBoard, allConfigurations);

    // Print the results
    cout << "Total Safe Configurations Found: " << allConfigurations.size() << "\n\n";
    for (int i = 0; i < allConfigurations.size(); i++) {
        cout << "Configuration " << i + 1 << ":\n";
        for (const string& row : allConfigurations[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}