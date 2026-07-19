class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;

        int prefsum = 0;
        for(int i=0;i<nums.size();i++){
            prefsum += nums[i];
            int rem = prefsum % k;
            if(m.find(rem) != m.end()){
                if(i - m[rem] >= 2) return true;
            }
            else m[rem] = i;
        }

        return false;
    }
};