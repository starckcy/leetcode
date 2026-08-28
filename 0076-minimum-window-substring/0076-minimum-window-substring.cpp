class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char c : t){
            mp[c]++;
        }

        int l=0, cnt=t.size();
        int mnlen = INT_MAX;
        int srt=0;

        for(int r=0; r<s.size(); r++){
            char ch = s[r];

            if(mp.count(ch)){
                if(mp[ch] > 0) cnt--;
                mp[ch]--;
            }

            while(cnt==0){
                if(r-l+1 < mnlen){
                    mnlen = r-l+1;
                    srt=l;
                }

                char lchar = s[l];

                if(mp.count(lchar)){
                    mp[lchar]++;
                    if(mp[lchar] > 0) cnt++;
                }

                l++;
            }
        }

        if (mnlen == INT_MAX) return "";
        return s.substr(srt, mnlen);
    }
};