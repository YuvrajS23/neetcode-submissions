class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pointer1 = 0;
        int pointer2 = numbers.size() - 1;
        while(pointer1 < pointer2){
            int sum = numbers[pointer1] + numbers[pointer2];
            if(sum == target) return {pointer1+1, pointer2+1};
            else if(sum > target) pointer2 -= 1;
            else pointer1 += 1;
        }
        return {};
    }
};
