class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        while (true){
            int mid = (left + right) / 2;
            if (left >= right){
                if (nums[mid] == target) return mid;
                return -1;
            }
            if (nums[mid] == target) return mid;
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
};
