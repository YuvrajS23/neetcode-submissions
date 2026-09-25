class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> charSet;
        for (auto ch: s){
            charSet.insert(ch);
        }
        int res = 0;
        for(auto c : charSet){
            int l = 0;
            int count = 0;
            for(int r = 0; r < s.length(); r++){
                if(s[r] == c){
                    count++;
                }
                while(r - l + 1 - count > k){
                    if(s[l] == c){
                        count--;
                    }
                    l++;
                }
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};
