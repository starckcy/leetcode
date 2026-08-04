class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        vector<bool> record(101);

        int mn = 101;
        int mx = 0;
        for(int i=0; i<nums.size(); i++){
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
            record[nums[i]] = true;
        }

        for(int i=mn;i<=mx;i++){
            if(record[i] == false) ans.push_back(i);
        }

        return ans;
    }
};