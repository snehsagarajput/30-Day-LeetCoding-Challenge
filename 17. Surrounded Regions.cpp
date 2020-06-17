/*


Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.


*/


class Solution {
public:
    void solve(vector<vector<char> >& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O')
                    solveDFS(board, i, j);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void solveDFS(vector<vector<char> > &board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '$';
            if (i > 0 && board[i - 1][j] == 'O') 
                solveDFS(board, i - 1, j);
            if (j < board[i].size() - 1 && board[i][j + 1] == 'O') 
                solveDFS(board, i, j + 1);
            if (i < board.size() - 1 && board[i + 1][j] == 'O') 
                solveDFS(board, i + 1, j);
            if (j > 0 && board[i][j - 1] == 'O') 
                solveDFS(board, i, j - 1);
        }
    }
};
