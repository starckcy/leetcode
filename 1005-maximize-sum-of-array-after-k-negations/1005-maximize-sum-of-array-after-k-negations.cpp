class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        
        int sum=0;
        for(int x : nums){
            pq.push(x);
            sum += x;
        }

        while(k){
            int x = pq.top();
            if(x == 0) break;

            pq.pop();
            sum -= x;
            pq.push(-x);
            sum += -x;
            k--;
        }

        return sum;
    }
};