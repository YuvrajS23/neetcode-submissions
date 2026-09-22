class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        unordered_map<int, int> freqList;
        for(auto num : nums){
            auto it = freqList.find(num);
            if(it != freqList.end()){
                it->second += 1;
            }
            else{
                freqList[num] = 1;
            }
        }
        for(auto entry : freqList){
            maxHeap.push({entry.second, entry.first});
        }
        vector<int> res;
        for(int i=0; i<k && !maxHeap.empty(); i++){
            auto topItem = maxHeap.top();
            res.push_back(topItem.second);
            maxHeap.pop();
        }

        return res;
    }
};
