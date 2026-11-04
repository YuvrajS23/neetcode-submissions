class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;

        int totalGasBal = 0;
        int res = 0;

        for(int i = 0; i < gas.size(); i++){
            totalGasBal += gas[i] - cost[i];
            if(totalGasBal < 0){
                totalGasBal = 0;
                res = i + 1;
            }
        }

        return res;
    }
};
