#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    bool row[9][9] = {};
    bool col[9][9] = {};
    bool box[9][9] = {};
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        char ch = board[r][c];
        if (ch == '.')
          continue;
        int d = ch - '1';
        int b = (r / 3) * 3 + (c / 3);
        if (row[r][d] || col[c][d] || box[b][d])
          return false;
        row[r][d] = col[c][d] = box[b][d] = true;
      }
    }
    return true;
  }
};

int main() {
  vector<vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
  };

  Solution s;
  bool res = s.isValidSudoku(board);
  (void)res;
}
