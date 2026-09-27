class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans;

        for(int i = 0; i < s.length(); i++){
            char ch = s[i];

            if(ch == '('){
                st.push(ans.length());
            }
            else if(ch == ')') {
                int srt = st.top(); st.pop();
                int end = ans.length() - 1;
                reverse(ans, srt, end);
            }
            else ans += ch;
        }

        return ans;
    }

    void reverse(string &sb, int srt, int end) {
        while(srt < end) {
            char temp = sb[srt];
            sb[srt] = sb[end];
            sb[end] = temp;
            srt++;
            end--;
        }
    }
};