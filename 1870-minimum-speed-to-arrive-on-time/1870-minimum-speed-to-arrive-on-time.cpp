class Solution {
public:
    bool check(int mid, vector<int>& dist, double hour){
        int n = dist.size();
        double time = 0.0;

        for(int i=0;i<n;i++){
            double t = (double) dist[i]/mid;
            if(i != n-1) time += ceil(t);
            else time += t;
        }

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        
        int ans=-1;
        int lo=1, hi=1e7;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid, dist, hour)==true){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};