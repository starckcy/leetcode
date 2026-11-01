class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mnele=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mnele = min(mnele, nums[i]);
        }
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            cnt += (nums[i] - mnele);
        }

        return cnt;
    }
};