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

    TreeNode* xparent = NULL;
    TreeNode* yparent = NULL;
    int xdepth = -1;
    int ydepth = -1;

    void dfs(TreeNode* root, TreeNode* parent, int depth, int x, int y){
        if(root==NULL) return;
        if(root->val == x){
            xparent = parent;
            xdepth = depth;
        }
        if(root->val == y){
            yparent = parent;
            ydepth = depth;
        }
        dfs(root->left, root, depth+1, x, y);
        dfs(root->right, root, depth+1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, 0, x, y);
        return xdepth == ydepth && xparent != yparent;
    }
};