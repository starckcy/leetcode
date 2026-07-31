class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char x : word){
            freq[x - 'a']++;
        }

        sort(freq.begin(), freq.end());

        int cnt=0;
        for(int i=25;i>=0 && freq[i] > 0;i--){
            cnt += freq[i] * (((25-i)/8) + 1);
        }

        return cnt;
    }
};