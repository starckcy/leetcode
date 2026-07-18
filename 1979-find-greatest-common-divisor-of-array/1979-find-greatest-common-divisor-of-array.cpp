class Solution {
public:

    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int s=1001, l=0;
        for(int x : nums){
            s = min(s, x);
            l = max(l, x);
        }

        return gcd(s, l);
    }
};