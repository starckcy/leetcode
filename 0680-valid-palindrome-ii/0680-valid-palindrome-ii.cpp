class Solution {
public:

    bool validPalindrome(string s){
        int flag=0;
        int i = 0, j = s.size() - 1;
        while(i <= j){
            if(s[i] != s[j]){
                j--;
                flag++;
            }
            else{
                i++;
                j--;
            }
        }

        if(flag>=2){
            flag=0;
            i = 0, j = s.size() - 1;
            while(i <= j){
                if(flag==2) return false;
                if(s[i] != s[j]){
                    i++;
                    flag++;
                }
                else{
                    i++;
                    j--;
                }
            }
        }

        return true;
    }
};