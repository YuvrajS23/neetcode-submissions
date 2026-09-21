class Solution {
public:
    bool isPalindrome(string s) {
        int l = s.length();
        int i = 0;
        while(i < l){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            else if(!isalnum(s[l])){
                l--;
                continue;
            }
            else{
                if(tolower(s[i]) != tolower(s[l])) return false;
                i++;
                l--;
            }
        }
        return true;
    }
};
