class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        int currele = nums[0];
        for(int i=0;i<nums.size(); currele++, i++){
            if(currele < nums[i]){
                ans.push_back(currele);
                i--;
            }
        }
        
        return ans;
    }
};