class Solution {
public:

    bool areEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        vector<int> need(26,0), window(26, 0);
        for(int x : s1){
            need[x - 'a']++;
        }
        
        int i=0, j=0;
        while(j<s2.size()){
            window[s2[j] - 'a']++;
            if(j-i+1 == s1.size() && areEqual(need, window)) return true;
            if(j-i+1 < s1.size()) j++;
            else{
                window[s2[i] - 'a']--;
                i++;
                j++;
            }
        }

        return false;
    }
};