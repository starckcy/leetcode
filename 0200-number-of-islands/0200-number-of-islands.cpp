class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int cc = 0; // no. of connected components
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c] == '0') continue; // water body

                // new cc
                cc++;
                grid[r][c] = '0'; // mark visited
                queue<pair<int, int>> q;
                q.push({r, c}); // store the src node
                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();

                    // go to all unvisited neighbours
                    int curRow = curr.first;
                    int curCol = curr.second;

                    // up
                    if(curRow-1 >= 0 && grid[curRow-1][curCol] == '1'){
                        q.push({curRow-1, curCol});
                        grid[curRow-1][curCol] = '0';
                    }

                    // down
                    if(curRow+1 < row && grid[curRow+1][curCol] == '1'){
                        q.push({curRow+1, curCol});
                        grid[curRow+1][curCol] = '0';
                    }

                    // left
                    if(curCol-1 >= 0 && grid[curRow][curCol-1] == '1'){
                        q.push({curRow, curCol-1});
                        grid[curRow][curCol-1] = '0';
                    }

                    // right
                    if(curCol+1 < col && grid[curRow][curCol+1] == '1'){
                        q.push({curRow, curCol+1});
                        grid[curRow][curCol+1] = '0';
                    }
                }
            }
        }

        return cc;
    }
};