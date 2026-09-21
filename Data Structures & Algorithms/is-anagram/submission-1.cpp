class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap, tMap;
        for(auto c: s){
            auto it = sMap.find(c);
            if(it != sMap.end()){
                sMap[c]++;
            }
            else{
                sMap[c] = 1;
            }
        }
        for(auto c: t){
            auto it = tMap.find(c);
            if(it != tMap.end()){
                tMap[c]++;
            }
            else{
                tMap[c] = 1;
            }
        }
        string searchString = s + t;
        for(auto c: searchString){
            auto it1 = sMap.find(c);
            auto it2 = tMap.find(c);
            if (it1 != sMap.end() && it2 != tMap.end()){
                if(sMap[c] != tMap[c]) return false;
            }
            else return false;
        }
        return true;
    }
};
