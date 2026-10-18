class Solution {
    int memoizedClimbStairs(int n, vector<int>& mem){
        int res;
        if(n == 1){
            mem[n] = 1;
            res = 1;
        }else if(n == 2){
            mem[n] = 2;
            res = 2;
        }
        else{
            if(mem[n] != -1) return mem[n];
            res = memoizedClimbStairs(n-1, mem) + memoizedClimbStairs(n-2, mem);
            mem[n] = res;
        }
        return res;
    }
public:
    int climbStairs(int n) {
        vector<int> mem(n+1, -1);
        return memoizedClimbStairs(n, mem);
    }
};
