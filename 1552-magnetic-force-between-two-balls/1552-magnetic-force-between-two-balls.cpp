class Solution {
public:

    bool canplace(vector<int>& pos, int m, int dist){
        int lastpos = pos[0];
        int cnt=1;
        for(int i=0; i<pos.size(); i++){
            if(pos[i] - lastpos >= dist){
                cnt++;
                lastpos = pos[i];
            }
            if(cnt >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int lo = 1;
        int hi = position.back() - position.front();
        int ans=0;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(canplace(position, m, mid)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
};