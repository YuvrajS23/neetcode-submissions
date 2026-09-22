class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anaGrams;
        for(auto str: strs){
            string tmp = str;
            sort(str.begin(), str.end());
            auto it = anaGrams.find(str);
            if (it != anaGrams.end()){
                it->second.push_back(tmp);
            }
            else{
                anaGrams[str] = {tmp};
            }
        }
        vector<vector<string>> res;
        res.reserve(anaGrams.size());
        for(auto& entry: anaGrams){
            res.push_back(entry.second);
        }
        return res;
    }
};
