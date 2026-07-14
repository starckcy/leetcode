class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int maxlen = 0;
        unordered_map<int, int> m;

        for(int j=0;j<fruits.size();j++){
            m[fruits[j]]++;

            while(m.size() > 2){
                m[fruits[i]]--;
                if(m[fruits[i]] == 0) m.erase(fruits[i]);
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
        }

        return maxlen;
    }
};