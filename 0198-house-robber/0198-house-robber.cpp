class Solution {
public:
    vector<int> dp;
    // int rec(vector<int>& nums, int i, int e){
    //     if(i > e) return 0;
    //     return max(rec(nums, i+2, e) + nums[i], rec(nums, i+1, e));
    // }

    // int ftd(vector<int>& nums, int i){
    //     if(i == nums.size()-1) return nums[i];
    //     if(i == nums.size()-2) return max(nums[i], nums[i+1]);
    //     if(dp[i] != -1) return dp[i];
    //     return dp[i] = max(ftd(nums, i+2) + nums[i], ftd(nums, i+1));
    // }

    int fbu(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        dp.clear();
        dp.resize(n);

        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1], nums[n-2]);
        for(int i=n-3;i>=0;i--){
            dp[i] = max(dp[i+2] + nums[i], dp[i+1]);
        }

        return dp[0];
    }
    
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105, -1);
        return fbu(nums);
    }
};