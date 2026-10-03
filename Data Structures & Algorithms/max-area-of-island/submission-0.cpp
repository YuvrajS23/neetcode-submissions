class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int& area){
        if(r < 0 || c < 0 || r >= grid.size()  || c >= grid[0].size() || grid[r][c] == 0){
            return;
        }

        grid[r][c] = 0;
        area = area + 1;

        for(int i = 0; i < 4; i++){
            dfs(grid, r + directions[i][0], c + directions[i][1], area);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(grid[i][j] == 1){
                    int a = 0;
                    dfs(grid, i, j, a);
                    maxArea = max(maxArea, a);
                }
            }
        }

        return maxArea;
    }
};
