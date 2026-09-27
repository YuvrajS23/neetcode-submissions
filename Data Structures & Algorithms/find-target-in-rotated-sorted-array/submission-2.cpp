class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while ( l < r ){
            int mid = l + (r - l)/2;
            if(nums[mid] < nums[r]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        int pivot = l;
        int end = nums[nums.size() - 1];
        if(target <= end){
            l = pivot;
            r = nums.size() - 1;
        }
        else{
            l = 0;
            r = pivot - 1;
        }
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return -1;
    }
};
