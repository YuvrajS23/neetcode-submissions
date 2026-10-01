class Solution {
    struct PointData {
        double dist;
        int x;
        int y;



        bool operator>(const PointData& other) const {
            return dist > other.dist;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<PointData, vector<PointData>, greater<PointData>> minHeap;
        for(auto point: points){
            int x = point[0];
            int y = point[1];
            minHeap.push({sqrt((x*x) + (y*y)) , x, y});
        }

        vector<vector<int>> res;
        for(int i = 0; i < k; i++){
            PointData p = minHeap.top();
            minHeap.pop();
            res.push_back({p.x, p.y});
        }

        return res;
    }
};
