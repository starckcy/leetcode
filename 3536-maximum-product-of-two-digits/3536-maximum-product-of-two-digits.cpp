class Solution {
public:
    int maxProduct(int n) {
        int l=n%10;
        n /= 10;
        int sl=n%10;
        n /= 10;

        if(sl > l) swap(sl, l);
        
        while(n){
            int d = n % 10;
            if(d > l){
                sl = l;
                l = d;
            }
            else if(d > sl){
                sl = d;
            }
            n /= 10;
        }

        return l * sl;
    }
};