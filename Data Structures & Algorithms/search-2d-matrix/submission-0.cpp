class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size();
        int numColumns = matrix[0].size();
        int totalElems = numRows * numColumns;
        int low = 0;
        int high = totalElems - 1;
        if (matrix[0][0] == target) return true;
        if (matrix[numRows - 1][numColumns - 1] == target) return true;
        while(low <= high){
            int mid = low + (high - low)/2;
            int midVal = matrix[mid / numColumns][mid % numColumns]; 
            if(midVal == target) return true;
            else if(midVal > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};
