class Solution {
public:

    int climbStairs(int n, vector<int>& costs) {
        int a = 0, b = 0, c = 0; 
        for(int cost : costs){
            int curr = cost + min({a+1, b+4, c+9});
            c = b;
            b = a;
            a = curr;
        }
        return a;
    }
};