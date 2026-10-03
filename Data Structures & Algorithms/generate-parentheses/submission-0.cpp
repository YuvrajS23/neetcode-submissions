class Solution {
    void generateBracks(int n, vector<string>& res, string& subset, int close, int open) {
        if(open == n && open == close){
            res.push_back(subset);
            return;
        }
        if(open < n){
            subset += "(";
            generateBracks(n, res, subset, close, open + 1);
            subset.pop_back();
        }
        if(close < open){
            subset += ")";
            generateBracks(n, res, subset, close + 1, open);
            subset.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string subset = "";
        generateBracks(n, res, subset, 0, 0);
        return res;
    }
};
