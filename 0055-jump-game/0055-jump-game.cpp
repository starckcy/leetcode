class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxidx=0;
        int i=0;
        while(i<nums.size()){
            if(mxidx < i) return false;
            mxidx = max(mxidx, i+nums[i]);
            i++;
        }
        return true;
    }
};