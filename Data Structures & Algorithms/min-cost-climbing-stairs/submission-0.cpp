class Solution {
    int memRecur(int n, vector<int>& cost, vector<int>& mem){
        if(n == 0 || n == 1) return 0;
        if(mem[n] != -1) return mem[n];
        int res1 = memRecur(n-1, cost, mem) + cost[n-1];
        int res2 = memRecur(n-2, cost, mem) + cost[n-2];
        mem[n] = min(res1, res2);
        return mem[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> mem(n+1, -1);
        return memRecur(n, cost, mem);
    }
};
