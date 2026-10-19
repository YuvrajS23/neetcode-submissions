class Solution {
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ROWS;
    int COLS;
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != 'O'){
            return;
        }

        board[r][c] = 'E';
        for(int i = 0; i < 4; i++){
            int row = r + dirs[i][0], col = c + dirs[i][1];
            dfs(board, row, col);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        if(ROWS == 0) return;
        COLS = board[0].size();

        for(int j = 0; j < COLS; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[ROWS-1][j] == 'O') dfs(board, ROWS-1, j);
        }

        for(int j = 0; j < ROWS; j++){
            if(board[j][0] == 'O') dfs(board, j, 0);
            if(board[j][COLS - 1] == 'O') dfs(board, j, COLS - 1);
        }

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'E'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
