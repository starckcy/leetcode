/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    struct pair{
        TreeNode* node;
        int row;
        int col;

        pair(TreeNode* node, int row, int col){
            this->node = node;
            this->row = row;
            this->col = col;
        }
    };

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> nodes;
        queue<pair> q;
        q.push(pair(root, 0, 0));

        while(!q.empty()){
            pair curr = q.front();
            q.pop();

            nodes.push_back({curr.col, curr.row, curr.node->val});
            if(curr.node->left){
                q.push(pair(curr.node->left, curr.row+1, curr.col-1));
            }
            if(curr.node->right){
                q.push(pair(curr.node->right, curr.row+1, curr.col+1));
            }
        }

        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;

        int prevCol = INT_MIN;
        for(auto &node : nodes){
            if(node[0]!=prevCol){
                ans.push_back({});
                prevCol = node[0];
            }
            ans.back().push_back(node[2]);
        }

        return ans;
    }
};