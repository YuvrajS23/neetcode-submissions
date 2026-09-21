class Solution {
public:
    int sumSquare(int n){
        int res = 0;
        while (n > 0){
            res += pow(n%10,2);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_set<int> seenNums;
        int sum = sumSquare(n);
        while (seenNums.find(sum) == seenNums.end()){
            if(sum == 1) return true;
            seenNums.insert(sum);
            sum = sumSquare(sum);
        }
        return false;
    }
};
