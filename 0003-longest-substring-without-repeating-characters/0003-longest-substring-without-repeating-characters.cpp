class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, maxlen = 0;
        unordered_map<char, int> m;

        for (int j = 0;j < s.size();j++){
            m[s[j]]++;

            while (m[s[j]] > 1){
                m[s[i]]--;
                if(m[s[i]] == 0) m.erase(s[i]);
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
        }

        return maxlen;
    }
};