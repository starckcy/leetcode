class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i == nums.size()-1) return nums[i];
        if(i == nums.size()-2) return max(nums[i], nums[i+1]);
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(solve(nums, i+2, dp) + nums[i], solve(nums, i+1, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};