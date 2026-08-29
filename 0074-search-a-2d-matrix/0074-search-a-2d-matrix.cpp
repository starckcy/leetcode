class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int top=0, bottom = m-1;
        int row = -1;

        while(top <= bottom){
            int mid = top + (bottom-top)/2;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target){
                row = mid;
                break;
            }
            else if(matrix[mid][0] > target) bottom = mid-1;
            else top = mid+1;
        }

        if(row==-1) return false;

        int lo=0, hi=n-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) hi = mid-1;
            else lo = mid+1;
        }
        return false;
    }
};