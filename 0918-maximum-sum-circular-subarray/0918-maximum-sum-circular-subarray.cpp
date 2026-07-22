class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum = nums[0];
        int minsum = nums[0];
        int mxsum = nums[0];
        int mnsum = nums[0];
        int totalsum = nums[0];

        for(int i=1;i<nums.size();i++){
            mxsum = max(mxsum + nums[i], nums[i]);
            maxsum = max(maxsum, mxsum);

            mnsum = min(mnsum + nums[i], nums[i]);
            minsum = min(minsum, mnsum);

            totalsum += nums[i];
        }

        int circularsum = totalsum - minsum;
        if(circularsum == 0) return maxsum;

        return max(maxsum, circularsum);
    }
};