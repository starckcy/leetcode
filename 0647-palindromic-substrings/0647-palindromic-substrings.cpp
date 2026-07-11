class Solution {
public:

    int expand(string &s, int l, int r,int &cnt) {
        while (l >= 0 && r < s.size() && s[l] == s[r]){
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int l=0, r=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            int str1 = expand(s, i, i, cnt);
            int str2 = expand(s, i, i+1, cnt);
        }

        return cnt;
    }
};