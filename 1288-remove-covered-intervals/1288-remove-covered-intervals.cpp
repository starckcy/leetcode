class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int cnt = 0;
        int maxEnd = 0;

        for (auto i : intervals) {
            if (i[1] > maxEnd) {
                cnt++;
                maxEnd = i[1];
            }
        }

        return cnt;
    }
};