class Solution {
    int dfs(int x, int y, int m, int n, vector<vector<int>>& mem){
        if(x == m-1 && y == n-1){
            mem[x][y] = 1;
            return mem[x][y];
        }
        else if(mem[x][y] != -1) return mem[x][y];
        else if(x <= m-2 && y <= n-2){ // right & down
            mem[x+1][y] = dfs(x+1, y, m, n, mem);
            mem[x][y+1] = dfs(x, y+1, m, n, mem);
            mem[x][y] = mem[x+1][y] + mem[x][y+1];
        }
        else if(x <= m-2){ // down
            mem[x+1][y] = dfs(x+1, y, m, n, mem);
            mem[x][y] = mem[x+1][y];
        }
        else if(y <= n-2){ // right
            mem[x][y+1]= dfs(x, y+1, m, n, mem);
            mem[x][y] = mem[x][y+1];
        }
        else{
            return 0;
        }
        return mem[x][y];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, mem);
    }
};
