class Solution {
public:

    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffmn(n);

        suffmn[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffmn[i] = min(suffmn[i+1], nums[i]);
        }

        int prefmx = INT_MIN;
        for(int i=0; i<n; i++){
            prefmx = max(prefmx, nums[i]);
            if(prefmx - suffmn[i] <= k){
                return i;
            }
        }

        return -1;
    }
};