class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = -1001, b = -1001, c = -1001;
        int x = 1001, y = 1001;

        for(int i : nums){
            int oa=a, ob=b, ox = x;

            a = max(a, i);
            b = max(b, min(oa, i));
            c = max(c, min(ob, i));

            x = min(x, i);
            y = min(y, max(ox, i));
        }

        return max(a*b*c, a*x*y);
    }
};