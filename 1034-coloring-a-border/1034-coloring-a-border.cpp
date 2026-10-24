class Solution {
public:

    vector<pair<int, int>> internal;
    void dfs(vector<vector<int>>& grid, int r, int c, int newColor, int originalColor){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != originalColor){
            return;
        }

        grid[r][c] = -newColor;
        dfs(grid, r+1, c, newColor, originalColor); // down
        dfs(grid, r, c-1, newColor, originalColor); // left
        dfs(grid, r-1, c, newColor, originalColor); // up
        dfs(grid, r, c+1, newColor, originalColor); // right

        // this code will be executed while coming back from recursion
        if(!(r == 0 || c == 0 || r == grid.size()-1 || c == grid[0].size()-1 || grid[r+1][c]!=-newColor || grid[r][c-1]!=-newColor || grid[r-1][c]!=-newColor || grid[r][c+1]!=-newColor)){
            internal.push_back({r, c});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int originalColor = grid[row][col];
        if(originalColor == color) return grid; 
        dfs(grid, row, col, color, originalColor);
        for(auto x : internal){
            int i = x.first;
            int j = x.second;
            grid[i][j] = originalColor;
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] < 0) grid[i][j] *= -1;
            }
        }
        return grid;
    }
};