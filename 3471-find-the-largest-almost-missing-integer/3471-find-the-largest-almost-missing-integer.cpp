class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        if(nums.size() == k) return *max_element(nums.begin(), nums.end());

        for(int i=0;i<=nums.size()-k;i++){
            for(int j=i;j<i+k;j++){
                mp[nums[j]]++;
            }
        }

        int lrg=-1;
        for(auto x : mp){
            if(x.second == 1){
                lrg = max(lrg, x.first);
            }
        }
        return lrg;
    }
};