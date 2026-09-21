class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buy = 0;
        int sell = 1;
        if (prices.size() < 2) return 0;
        while (sell < prices.size()){
            if (prices[sell] > prices[buy]){
                int currProfit = prices[sell] - prices[buy];
                maxProfit = max(currProfit, maxProfit);
            }
            else{
                buy = sell;
            }
            sell++;
        }
        return maxProfit;
    }
};
