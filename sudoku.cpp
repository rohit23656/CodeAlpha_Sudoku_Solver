#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int number) {
    
        for(int i = 0; i < board.size(); i++)
        {
            if (board[i][col] == (char)(number + '0'))
            {
                return false;
            }
        }
        for(int j = 0; j < board.size(); j++)
        {
            if (board[row][j] == (char)(number + '0'))
            {
                return false;
            }
        }
        int sr = 3 * (row / 3);
        int sc = 3 * (col / 3);
        for(int i = sr; i < sr + 3; i++)
        {
            for (int j = sc; j < sc + 3; j++)
            {
                if (board[i][j] == (char)(number + '0'))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int row, int col) {
        if (row == board.size()) {
            return true;
        }
        int nrow = 0;
        int ncol = 0;
        if (col == board.size() - 1) {
            nrow = row + 1;
            ncol = 0;
        } 
        else{
            nrow = row;
            ncol = col + 1;
        }
        if (board[row][col] != '.') {
            if (helper(board, nrow, ncol)) 
            {
                return true;
            }
        } else {
            for (int i = 1; i <= 9; i++) {
                if (isSafe(board, row, col, i)) {
                    board[row][col] = (char)(i + '0');
                    if (helper(board, nrow, ncol)) {
                        return true;
                    } else {
                        board[row][col] = '.';
                    }
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
int main() {
    Solution solution;
    vector<vector<char>> board(9, vector<char>(9, '.'));

    cout << "Enter the Sudoku board (use . for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    solution.solveSudoku(board);
    cout << "Solved Sudoku board:\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}

