class Solution {
public:
    int maxDepth(string s) {
        int mxcnt=INT_MIN, cnt=0;
        for(int x : s){
            if(x == '('){
                cnt++;
                mxcnt=max(mxcnt, cnt);
            }
            if(x == ')'){
                cnt--;
            }
        }
        return (mxcnt==INT_MIN) ? 0 : mxcnt;
    }
};