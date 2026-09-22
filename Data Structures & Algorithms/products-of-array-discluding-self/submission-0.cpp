#include <deque>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        deque<int> prefixProd = {1};
        int prod = 1;
        for(int i = 1; i < nums.size(); i++){
            prod *= nums[i-1];
            prefixProd.push_back(prod);
        }
        deque<int> suffixProd = {1};
        prod = 1;
        for(int i = nums.size()-2; i >= 0; i--){
            prod *= nums[i+1];
            suffixProd.push_front(prod);
        }
        vector<int> res;
        for(int i = 0; i < prefixProd.size() && i < suffixProd.size(); i++){
            res.push_back(prefixProd[i] * suffixProd[i]);
        }
        return res;
    }
};
