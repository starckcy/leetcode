class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int cnt=0, prefsum = 0;

        for(int i=0;i<nums.size();i++){
            prefsum += nums[i];
            int rem = prefsum % k;
            if(rem < 0) rem += k;
            if(m.find(rem) != m.end()){
                cnt += m[rem];
            }
            m[rem]++;
        }

        return cnt;
    }
};