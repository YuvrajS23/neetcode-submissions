class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        unordered_set<char> hasAppeared;
        int l = 0;
        hasAppeared.insert(s[0]);
        int r = l + 1;
        int longestSubstring = 1;
        while(r < s.size()){
            while(hasAppeared.find(s[r]) != hasAppeared.end()){
                hasAppeared.erase(s[l]);
                l++;
                continue;
            }
            hasAppeared.insert(s[r]);
            r++;
            longestSubstring = max(longestSubstring, r - l);
        }
        return longestSubstring;
    }
};
