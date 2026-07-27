class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for(int x : nums){
            if(x >= a){
                b = a;
                a = x; 
            }
            if(x < a && x >= b){
                b = x;
            }
        }
        return (a-1)*(b-1);
    }
};