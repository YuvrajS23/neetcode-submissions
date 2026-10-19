class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        queue<pair<int, int>> pacSide;
        for(int j = 0; j < COLS; j++){
            pacSide.push({0, j});
        }
        for(int i = 0; i < ROWS; i++){
            pacSide.push({i, 0});
        }

        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!pacSide.empty()){
            int row = pacSide.front().first;
            int col = pacSide.front().second;
            pacSide.pop();
            pacific[row][col] = true;
            for(int i = 0; i < 4; i++){
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                if(r < 0 || r >= ROWS || c < 0 || c >= COLS) continue;

                if(heights[r][c] >= heights[row][col]){
                    if(!pacific[r][c]) pacSide.push({r, c});
                }
            }
        }

        queue<pair<int, int>> atlSide;
        for(int j = 0; j < COLS; j++){
            atlSide.push({ROWS - 1, j});
        }
        for(int i = 0; i < ROWS; i++){
            atlSide.push({i, COLS - 1});
        }

        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));
        while(!atlSide.empty()){
            int row = atlSide.front().first;
            int col = atlSide.front().second;
            atlSide.pop();
            atlantic[row][col] = true;
            for(int i = 0; i < 4; i++){
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                if(r < 0 || r >= ROWS || c < 0 || c >= COLS) continue;

                if(heights[r][c] >= heights[row][col]){
                    if(!atlantic[r][c]) atlSide.push({r, c});
                }
            }
        }

        vector<vector<int>> res;

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
