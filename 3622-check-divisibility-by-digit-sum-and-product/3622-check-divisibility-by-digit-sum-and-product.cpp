class Solution {
public:

    bool check(int n){
        int sum=0, prod=1, d=n;
        while(n){
            sum += n%10;
            prod *= n%10;
            n /= 10;
        }
        
        return (d%(sum+prod)==0) ? true : false;
    }
    bool checkDivisibility(int n) {
        return check(n);
    }
};