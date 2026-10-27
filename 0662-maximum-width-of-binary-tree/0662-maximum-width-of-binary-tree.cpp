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
    vector<unsigned long long> firstidx;
    unsigned long long mxwidth = 0;

    void dfs(TreeNode* root, int level, unsigned long long idx){
        if (!root) return;
        if (level == firstidx.size()) firstidx.push_back(idx);

        unsigned long long normalized = idx - firstidx[level];
        mxwidth = max(mxwidth, normalized + 1);

        dfs(root->left, level + 1, 2 * normalized);
        dfs(root->right, level + 1, 2 * normalized + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0, 0);
        return static_cast<int>(mxwidth);
    }
};