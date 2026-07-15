class Solution {
public:

    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int sumeven=0;
        int x = 2;
        for(int i=1;i<=n;i++){
            sumeven += x;
            x += 2;
        }
        int sumodd=0;
        x = 1;
        for(int i=1;i<=n;i++){
            sumodd += x;
            x += 2;
        }
        
        return gcd(sumeven, sumodd);
    }
};