class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int operand = 1;
        int carry = 0;
        while(i>=0){
            if(digits[i] < 9){
                digits[i] += operand + carry;
                return digits;
            }
            else{
                digits[i] = 0;
                carry = 1;
            }
            if (i == digits.size() - 1) operand = 0;
            i--;
        }
        vector<int> res = {1};
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};
