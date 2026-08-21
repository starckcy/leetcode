class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        unordered_set<int> set;
        vector<int> ans;
        for(int x : nums1){
            mp[x]++;
        }
        for(int x : nums2){
            if(mp.find(x) != mp.end()){
                set.insert(x);
            }
        }

        for(auto x : set){
            ans.push_back(x);
        }
        return ans;
    }
};