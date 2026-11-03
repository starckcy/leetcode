class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt=0, mx=INT_MIN;
        for(int x : nums) mx = max(mx, x);
        for(int i : nums) cnt += abs(mx - i);
        return cnt;
    }
};