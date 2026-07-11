class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();

        vector<int> ans;
        if(s.size() < p.size()) return ans;

        vector<int> need(26,0), window(26, 0);
        for(int x : p){
            need[x - 'a']++;
        }
        
        int i=0;
        while(i<k){
            window[s[i] - 'a']++;
            i++;
        }
        if(window==need) ans.push_back(0);

        int j=k;
        while(j<n){
            window[s[j] - 'a']++;
            window[s[j-k] - 'a']--;
            if(window==need) ans.push_back(j-k+1);
            j++;
        }

        return ans;
    }
};