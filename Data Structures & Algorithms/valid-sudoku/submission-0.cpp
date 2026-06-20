#include <set>
#include <map>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<int>> rows;
        map<int, set<int>> cols;
        map<std::pair<int, int>, set<int>> squares;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (rows[i].contains(board[i][j]) || cols[j].contains(board[i][j]) || squares[{(i/3), (j/3)}].contains(board[i][j])) {
                    return false;
                }

                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                squares[{(i/3), (j/3)}].insert(board[i][j]);

            }
        }

        return true;


    }
};
