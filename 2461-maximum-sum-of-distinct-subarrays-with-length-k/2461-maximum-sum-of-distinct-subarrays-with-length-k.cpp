class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        long long mxs=0, s=0;

        for(int i=0;i<n;i++){
            s += nums[i];
            m[nums[i]]++;

            if(i >= k){
                s -= nums[i - k];
                m[nums[i-k]]--;
                if(m[nums[i-k]] == 0) m.erase(nums[i-k]);
            }

            if(i >= k-1 && m.size()==k) mxs = max(mxs, s);
            
        }

        return mxs;


    }
};