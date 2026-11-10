class Solution {
public:

    int solve(int n, vector<int>& costs, vector<int>& dp){
        if (n==0) return 0;
        if(dp[n]!=-1) return dp[n];

        int ans = INT_MAX;

        for (int jump=1; jump<=3; jump++){
            if (n >= jump){
                int curr = solve(n - jump, costs, dp) 
                                + costs[n - 1] 
                                + (jump * jump);

                ans = min(ans, curr);
            }
        }
        return dp[n] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return solve(n, costs, dp);
    }
};