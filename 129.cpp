//129. Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        /*
        T: O(N)
        S: O(logN)
        */
        if (!root) return 0;
        int sum = 0;
        helper(root, sum, 0);
        return sum;
    }
    void helper(TreeNode* root, int &sum, int num) {
        if (!root->left && !root->right) {
            sum += num * 10 + root->val;
            return;
        }
        if (root->left) helper(root->left, sum, num * 10 + root->val);
        if (root->right) helper(root->right, sum, num * 10 + root->val);
    }
};
