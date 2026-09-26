class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftBdry(n, -1);
        stack<int> stack;
        for(int i = 0; i < n; i++){
            while(!stack.empty() && heights[stack.top()] >= heights[i]){
                stack.pop();
            }
            if(!stack.empty()){
                leftBdry[i] = stack.top();
            }
            stack.push(i);
        }

        while(!stack.empty()) stack.pop();

        vector<int> rightBdry(n, n);
        for(int i = n - 1; i >= 0; i--){
            while(!stack.empty() && heights[stack.top()] >= heights[i]){
                stack.pop();
            }
            if(!stack.empty()){
                rightBdry[i] = stack.top();
            }
            stack.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++){
            leftBdry[i] += 1;
            rightBdry[i] -= 1;
            maxArea = max(maxArea, heights[i] * (rightBdry[i] - leftBdry[i] + 1));
        }
        return maxArea;
    }
};
