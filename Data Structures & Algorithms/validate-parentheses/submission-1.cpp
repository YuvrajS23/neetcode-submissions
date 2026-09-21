class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brac = {{')','('}, {'}','{'}, {']','['}};
        vector<char> stk;
        for(auto c: s){
            if (!stk.empty()){
                if (brac[c] == stk.back()){
                    stk.pop_back();
                    continue;
                }
            }
            stk.push_back(c);
        }
        return stk.empty();
    }
};
