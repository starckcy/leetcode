class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited.insert(curr);

            for(int x : rooms[curr]){
                if(visited.find(x) == visited.end()){
                    visited.insert(x);
                    q.push(x);
                }
            }
        }

        return visited.size() == rooms.size();
    }
};