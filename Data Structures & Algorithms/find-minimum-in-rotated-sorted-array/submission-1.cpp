class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size() - 1;
        int l = 0;
        while(l < n){
            int mid = l+ (n - l)/2;
            if(nums[mid] > nums[n]){
                l = mid + 1;
            }
            else{
                n = mid;
            }
        }
        return nums[l];
    }
};
