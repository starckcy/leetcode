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

    bool comparison(TreeNode* root, TreeNode* sroot){
        if(root==NULL && sroot==NULL) return true;
        if(root==NULL || sroot==NULL) return false;
        if(root->val != sroot->val) return false;
        return comparison(root->left, sroot->left) && comparison(root->right, sroot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(comparison(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};