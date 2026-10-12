/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> prnt;
    void buildparent(TreeNode* root, TreeNode* parent){
        if(root==NULL) return;
        prnt[root] = parent;

        buildparent(root->left, root);
        buildparent(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildparent(root, NULL);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);
        int dist = 0;

        while(!q.empty()){
            if(dist==k) break;
            int size = q.size();

            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && visited.insert(curr->left).second){
                    q.push(curr->left);
                }
                if(curr->right && visited.insert(curr->right).second){
                    q.push(curr->right);
                }
                if(prnt[curr] && visited.insert(prnt[curr]).second){
                    q.push(prnt[curr]);
                }
            }
            dist++;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};