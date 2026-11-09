class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<bool> valid(n, true);
        for(int i = 0; i < n; i++){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]){
                valid[i] = false;
            }
        }

        vector<int> res = {0, 0, 0};

        for(int i = 0; i < n; i++){
            if(valid[i]){
                for(int j = 0; j < 3; j++){
                    res[j] = max(res[j], triplets[i][j]);
                }
            }
        }

        for(int j = 0; j < 3; j++){
            if(res[j] != target[j]) return false;
        }

        return true;
    }
};
