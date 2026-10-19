class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshTomatoes = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    freshTomatoes++;
                }
            }
        }

        if(freshTomatoes == 0) return 0;

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int countMins = 0;
        while(!q.empty()){
            int size = q.size();
            for(int k = 0; k < size; k++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int r = row + dirs[i][0];
                    int c = col + dirs[i][1];

                    if(r < 0 || r >= m || c < 0 || c >= n) continue;

                    if(grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r, c});
                    }
                }

            }
            countMins++;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return countMins - 1;
    }
};
