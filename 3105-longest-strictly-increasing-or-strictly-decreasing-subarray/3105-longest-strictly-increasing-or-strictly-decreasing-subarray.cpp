class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int si=1, sd=1;
        int msi=-1, msd=-1;
        for(int x=0; x<nums.size();x++){
            si=1;
            for(int i=x;i<nums.size()-1;i++){
                if(nums[i] >= nums[i+1]) break;
                if(nums[i] < nums[i+1]) si++;
            }
            msi = max(msi, si);
        }

        for(int x=0;x<nums.size();x++){
            sd=1;
            for(int i=x;i<nums.size()-1;i++){
                if(nums[i] <= nums[i+1]) break;
                if(nums[i] > nums[i+1]) sd++;
            }
            msd = max(msd, sd);
        }
        
        return max(msi, msd);
    }
};