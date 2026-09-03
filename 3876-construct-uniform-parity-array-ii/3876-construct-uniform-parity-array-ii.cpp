class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mnodd = INT_MAX;
        int mneven = INT_MAX;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]%2!=0){
                mnodd = min(mnodd, nums1[i]);
            }
            if(nums1[i]%2==0){
                mneven = min(mneven, nums1[i]);
            }
        }
        if(mnodd==INT_MAX) return true;
        if(mneven > mnodd) return true;
        return false;
    }
};