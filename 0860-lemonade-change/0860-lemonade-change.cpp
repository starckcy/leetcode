class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bal=0;
        int a=0, b=0;
        for(int i : bills){
            if(i == 5) a++;
            if(i == 10){
                if(a == 0) return false;
                a--;
                b++;
            }
            if(i == 20){
                if(b > 0 && a > 0){
                    b--;
                    a--;
                }
                else if(a >= 3){
                    a-=3;
                }
                else return false;
            }
        }
        return true;
    }
};