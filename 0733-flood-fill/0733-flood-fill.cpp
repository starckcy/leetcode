class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c, int newcolor, int initialcolor){
        int n = image.size();
        int m = image[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m) return;
        if(image[r][c] != initialcolor) return;

        image[r][c] = newcolor;
        dfs(image, r+1, c, newcolor, initialcolor); // down
        dfs(image, r-1, c, newcolor, initialcolor); // up
        dfs(image, r, c+1, newcolor, initialcolor); // right
        dfs(image, r, c-1, newcolor, initialcolor); // left
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};