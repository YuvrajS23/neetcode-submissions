class Solution {
    int dhoomMachale(int n, vector<int>& nums, vector<int>& money){
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        if(money[n] != -1) return money[n];
        int c1 = dhoomMachale(n-2, nums, money) + nums[n-1];
        int c2 = dhoomMachale(n-1, nums, money);

        money[n] = max(c1, c2);

        return money[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> money(n+1, -1);

        return dhoomMachale(n, nums, money);
    }
};
