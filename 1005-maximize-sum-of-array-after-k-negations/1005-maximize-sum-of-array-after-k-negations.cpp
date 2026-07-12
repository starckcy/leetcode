class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int x : nums){
            pq.push(x);
        }

        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
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