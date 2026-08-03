class Solution {
public:

    int mncost(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = cost[i] + min(mncost(cost, i + 1, dp), mncost(cost, i + 2, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(mncost(cost, 0, dp), mncost(cost, 1, dp));
    }
};