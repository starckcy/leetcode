class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size();
        int j = t.size();

        int skips=0, skipt=0;
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    skips++;
                    i--;
                }
                else if(skips){
                    skips--;
                    i--;
                }
                else break;
            }

            while(j >= 0){
                if(t[j] == '#'){
                    skipt++;
                    j--;
                }
                else if(skipt){
                    skipt--;
                    j--;
                }
                else break;
            }

            if(i >= 0 && j >= 0){
                if(s[i] != t[j]) return false;
            }
            else{
                if(i >= 0 || j >= 0) return false;
            }

            i--;
            j--;
        }
        return true;
    }
};