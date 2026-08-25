class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> mul;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                mul.push_back(nums[i]);
            }
        }

        sort(mul.begin(), mul.end());
        int j=1;
        for(int i=0;i<mul.size();i++){
            if(k * j == mul[i]){
                j++;
            }
        }

        return k*j;
    }
};