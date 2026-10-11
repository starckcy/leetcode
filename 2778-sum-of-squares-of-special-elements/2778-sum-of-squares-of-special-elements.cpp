class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum=0, j=1;
        for(int i=0;i<n;i++){
            if(n % j == 0){
                sum = sum + (nums[i] * nums[i]);
            }
            j++;
        }

        return sum;
    }
};