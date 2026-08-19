class Solution {
public:
    bool check(vector<int> bloomDay, int m, int k, int d){
        int cnt=0, bouquets=0;
        for(int bloom : bloomDay){
            if(bloom <= d){
                cnt++;
                if(cnt == k){
                    bouquets++;
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long) m*k > n) return -1;

        int lo=INT_MAX, hi=INT_MIN;
        for(int i=0;i<n;i++){
            lo = min(lo, bloomDay[i]);
            hi = max(hi, bloomDay[i]);
        }

        int ans=-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(check(bloomDay, m, k, mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};