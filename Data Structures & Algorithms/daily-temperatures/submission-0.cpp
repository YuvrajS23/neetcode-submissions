class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            if(!stk.empty()){
                while(!stk.empty() && temperatures[i] > stk.top().first){
                    res[stk.top().second] = i - stk.top().second;
                    stk.pop();
                }
            }
            stk.push({temperatures[i], i});
        }
        return res;
    }
};
