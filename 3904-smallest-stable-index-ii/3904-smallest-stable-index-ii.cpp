class Solution {
public:

    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefmx(n);
        vector<int> suffmn(n);

        prefmx[0] = nums[0];
        for(int i=1;i<n;i++){
            prefmx[i] = max(prefmx[i-1], nums[i]);
        }

        suffmn[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffmn[i] = min(suffmn[i+1], nums[i]);
        }

        for(int i=0; i<n; i++){
            if(prefmx[i] - suffmn[i] <= k){
                return i;
            }
        }

        return -1;
    }
};