class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int stone: stones){
            maxHeap.push(stone);
        }

        while(maxHeap.size() > 1){
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            if(stone1 == stone2) continue;
            else if(stone1 > stone2) maxHeap.push(stone1 - stone2);
            else maxHeap.push(stone2 - stone1);
        }

        if(!maxHeap.empty()) return maxHeap.top();
        else return 0;
    }
};
