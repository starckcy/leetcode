class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = INT_MIN;
        int minsum = INT_MAX;
        int mxsum = 0;
        int mnsum = 0;

        for(int i=0;i<nums.size();i++){
            mxsum += nums[i];
            maxsum = max(maxsum, mxsum);
            if(mxsum < 0) mxsum = 0;

            mnsum += nums[i];
            minsum = min(minsum, mnsum);
            if(mnsum > 0) mnsum = 0;
        }

        return max(maxsum, abs(minsum));
    }
};