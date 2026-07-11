class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        long long mxs=0, s=0;

        int i=0;
        while(i<k){
            m[nums[i]]++;
            s += nums[i];
            i++;
        }
        if(m.size() == k) mxs = s;

        while(i < n){
            m[nums[i]]++;
            m[nums[i-k]]--;
            if(m[nums[i-k]] == 0) m.erase(nums[i-k]);

            s += nums[i];
            s -= nums[i-k];
            if(m.size() == k) mxs = max(mxs, s);
            i++;
            
        }

        return mxs;
    }
};