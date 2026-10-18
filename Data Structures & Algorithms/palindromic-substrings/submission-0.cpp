class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            // Odd Palindromes
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                count++;
                l--;
                r++;
            }

            // Even Palindromes
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                count++;
                l--;
                r++;
            }
        }

        return count;
    }
};
