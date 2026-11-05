class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        string res = "";
        for(int i = 1; i <= strs[0].size(); i++){
            string cur = strs[0].substr(0, i);
            for(int j = 1; j < strs.size(); j++){
                if(cur != strs[j].substr(0, i)){
                    break;
                }
                if(j == strs.size() - 1) res = cur;
            }
        }
        return res;
    }
};