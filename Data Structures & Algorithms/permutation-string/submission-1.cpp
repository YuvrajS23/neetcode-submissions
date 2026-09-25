class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        sort(s1.begin(), s1.end());
        int sz = s1.size();
        string sub;
        for(int l = 0; l <= s2.size() - sz; l++){
            sub = s2.substr(l, sz);
            sort(sub.begin(), sub.end());
            if(sub == s1) return true;
        }
        return false;
    }
};
