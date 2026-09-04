class Solution {
public:
    int fmx(int i, vector<int> nums){
        int j=0, mx = INT_MIN;
        while(j <= i){
            mx = max(mx, nums[j]);
            j++;
        }
        return mx;
    }
    int fmn(int i, vector<int> nums){
        int j=i, mn = INT_MAX;
        while(j <= nums.size()-1){
            mn = min(mn, nums[j]);
            j++;
        }
        return mn;
    }
    
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        while(i<n){
            int mx = fmx(i, nums);
            int mn = fmn(i, nums);
            
            if(mx-mn <= k){
                return i;
            }
            i++;
        }
        return -1;
    }
};