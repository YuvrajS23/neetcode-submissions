class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resIdx = 0;
        int resLen = 0;

        // Odd
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(resLen <= r - l + 1){
                    resLen = r - l + 1;
                    resIdx = l;
                }
                l--;
                r++;
            }
        }

        // Even
        for(int i = 0; i < n; i++){
            int l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(resLen <= r - l + 1){
                    resLen = r - l + 1;
                    resIdx = l;
                }
                l--;
                r++;
            }
        }


        return s.substr(resIdx, resLen);
    }
};
