class Solution {
public:

    int sum=0;

    void sqsum(int n){
        sum = sum + (n*n);
    }
    int sumCounts(vector<int>& nums) {

        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.clear();
            for(int j=i;j<nums.size();j++){
                s.insert(nums[j]);
                sqsum(s.size());
            }
        }

        return sum;
    }
};