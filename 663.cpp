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
    bool checkEqualTree(TreeNode* root) {
        if (!root) return false;
        unordered_set<int> hset;
        int total = helper(root, root, hset);
        if (total % 2 == 0 && hset.count(total / 2 ) > 0)
            return true;
        else 
            return false;
    }
    int helper(TreeNode* top_root, TreeNode* root, unordered_set<int> &hset) {
        if (!root) return 0;
        int sum = root->val + helper(top_root, root->left, hset) + helper(top_root, root->right, hset);
        if (root != top_root) hset.insert(sum);
        return sum;
    }
};
