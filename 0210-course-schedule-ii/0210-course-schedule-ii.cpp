class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
        vector<list<int>> graph(v);
        vector<int> indegree(v, 0);

        for(vector<int>& edge : prerequisites){
            int a = edge[0];
            int b = edge[1];

            graph[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        int vis = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            vis++;
            for(auto nbr : graph[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(vis == v) return ans;
        else return {};
    }
};