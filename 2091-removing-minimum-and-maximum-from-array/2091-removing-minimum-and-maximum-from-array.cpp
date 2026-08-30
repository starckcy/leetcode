class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mx=INT_MIN, mn=INT_MAX;
        int mxi=-1, mni=-1;
        
        for(int i=0;i<n;i++){
            if(mx < nums[i]){
                mx = nums[i];
                mxi = i;
            }
            if(mn > nums[i]){
                mn = nums[i];
                mni = i;
            }
        }

        int left = min(mni, mxi);
        int right = max(mni, mxi);

        return min({right+1, n-left, left+1 + n-right});
    }
};