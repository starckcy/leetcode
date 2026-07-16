class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int prefsum=0;
        int cnt=0;

        for(int x : nums){
            prefsum += x;
            if(m.find(prefsum - k) != m.end()){
                cnt += m[prefsum - k];
            }
            m[prefsum]++;
        }
        return cnt;
    }
};