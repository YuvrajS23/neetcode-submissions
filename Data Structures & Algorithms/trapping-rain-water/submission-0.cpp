class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefixMax(height.size(), 0);
        int pMax = 0;
        for(int i = 0; i < height.size(); i++){
            if(height[i] >= pMax){
                pMax = height[i];
            }
            prefixMax[i] = pMax;
        }
        vector<int> suffixMax(height.size(), 0);
        int sMax = 0;
        for(int i = height.size() - 1; i >= 0; i--){
            if(height[i] >= sMax){
                sMax = height[i];
            }
            suffixMax[i] = sMax;
        }
        int res = 0;
        for(int i = 0; i < height.size(); i++){
            res += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        return res;
    }
};
