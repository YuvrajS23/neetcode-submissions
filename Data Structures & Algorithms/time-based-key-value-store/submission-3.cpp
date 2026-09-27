class TimeMap {
    unordered_map<string, vector<pair<int, string>>> hashMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& lst = hashMap[key];
        int r = lst.size() - 1;
        int l = 0;
        string res = "";
        while(l <= r){
            int mid = l + (r - l) / 2;
            int curr = lst[mid].first;
            if(curr <= timestamp){
                res = lst[mid].second;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return res;
    }
};
