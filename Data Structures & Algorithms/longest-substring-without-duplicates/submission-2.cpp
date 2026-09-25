class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_set<char> hasAppeared;
        int l = 0;
        int longestSubstring = 1;
        for (int r = 0; r < s.size(); r++){
            while(hasAppeared.find(s[r]) != hasAppeared.end()){
                hasAppeared.erase(s[l]);
                l++;
            }
            hasAppeared.insert(s[r]);
            longestSubstring = max(longestSubstring, r - l + 1);
        }
        return longestSubstring;
    }
};
