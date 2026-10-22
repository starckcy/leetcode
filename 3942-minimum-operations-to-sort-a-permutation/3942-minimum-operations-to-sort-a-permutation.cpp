class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int f = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                f=i;
                break;
            }
        }

        bool right = true, left = true;
        for(int i=1;i<n;i++){
            if (nums[(f+i -1) % n] > nums[(f+i) % n]) right = false;
            if (nums[(f-i+n) % n] < nums[(f-i+n + 1) % n]) left = false;
        }

        int ans = INT_MAX;
        if(right) ans = min(ans, min(f, n-f + 2));
        if(left) ans = min(ans, min(f + 2, n-f));

        return ans == INT_MAX ? -1 : ans;
    }
};