class Solution {
public:
    bool validPalindrome(string s) {
        string str = "";
        for(char i : s){
            if(isalnum(i)) str += tolower(i);
        }

        int flag=0;
        int i = 0, j = str.size() - 1;
        while(i <= j){
            if(str[i] != str[j]){
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
            i = 0, j = str.size() - 1;
            while(i <= j){
                if(flag==2) return false;
                if(str[i] != str[j]){
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