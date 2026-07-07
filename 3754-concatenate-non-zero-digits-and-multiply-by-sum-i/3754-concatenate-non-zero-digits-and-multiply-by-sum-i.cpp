class Solution {
public:

    int rev(int n){
        int x=0;
        while(n){
            x = x * 10 + (n % 10);
            n /= 10;
        }
        return x;
    }

    long long sumAndMultiply(int n) {
        int z=0;
        while(n){
            int d = n % 10;
            if(d) z = z * 10 + d;
            n /= 10;
        }

        z = rev(z);

        int x = z;
        int s=0;
        while(z){
            s += z%10;
            z /= 10;
        }

        return (long long)x*s;
    }
};