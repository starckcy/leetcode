class Solution {
public:
    int solve(vector<vector<int>>& grid, int sr, int sc, int er, int ec, vector<vector<int>>& dp){
        if(sr > er || sc > ec) return INT_MAX;
        if(sr==er && sc==ec) return grid[sr][sc];
        if(dp[sr][sc] != -1) return dp[sr][sc];

        int down = solve(grid, sr+1, sc, er, ec, dp);
        int right = solve(grid, sr, sc+1, er, ec, dp);

        return dp[sr][sc] = grid[sr][sc] + min(down, right); 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, 0, 0, m-1, n-1, dp);
    }
};