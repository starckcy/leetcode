class Solution {
public:
    int digitprod(int n){
        int dprod = 1;
        while(n){
            dprod *= n % 10;
            n /= 10;
        }
        return dprod;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<101;i++){
            int prod=digitprod(i);
            if(prod%t==0){
                return i;
            }
        }
        return 0;
    }
};