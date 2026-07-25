class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        unordered_map<char, int> m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }

        priority_queue<pair<char, int>> pq;
        for(auto x : m){
            pq.push({x.first, x.second});
        }

        string ans = "";
        while(!pq.empty()){
            pair<char, int> largest = pq.top();
            pq.pop();

            int len = min(repeatLimit, largest.second);
            for(int i=0;i<len;i++){
                ans += largest.first;
            }

            if(largest.second - len > 0){
                if(pq.empty()){
                    return ans;
                }

                pair<char, int> seclargest = pq.top();
                pq.pop();
                ans += seclargest.first;
                
                if(seclargest.second - 1 > 0){
                    pq.push({seclargest.first, seclargest.second - 1});
                }
                pq.push({largest.first, largest.second - len});
            }
        }
        return ans;
    }
};