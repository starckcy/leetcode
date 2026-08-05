class Solution {
public:
    int solve(int sr, int sc, int er, int ec, vector<vector<int>>& dp, vector<vector<int>>& og){
        if(sr>er || sc>ec) return 0;
        if(og[sr][sc] == 1) return 0;
        if(sr==er && sc==ec) return 1;
        if(dp[sr][sc] != -1) return dp[sr][sc];
        return dp[sr][sc] = solve(sr, sc+1, er, ec, dp, og) + solve(sr+1, sc, er, ec, dp, og);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m-1, n-1, dp, obstacleGrid);

    }
};