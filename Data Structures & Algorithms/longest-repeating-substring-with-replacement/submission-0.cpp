class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> charSet;
        for(auto c: s){
            charSet.insert(c);
        }
        int finalRes = 0;
        for(auto ch : charSet){
            int l = 0;
            int count = 0;
            for (int r = 0; r < s.size(); r++){
                if(s[r] == ch){
                    count++;
                }
                while(r - l + 1 - count > k){
                    if(s[l] == ch) count--;
                    l++;
                }
                finalRes = max(finalRes, r - l + 1);
            }
        }
        return finalRes;
    }
};
