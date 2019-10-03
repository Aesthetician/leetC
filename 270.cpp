//270. Closest Binary Search Tree Value
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//iteration version
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        TreeNode* crt = root;
        while (crt) {
            res = abs(target - crt->val) < abs(target - res) ? crt->val : res;
            crt = target > crt->val ? crt->right : crt->left;
        }
        return res;
    }
};


//recursive version
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        helper(res, root, target);
        return res;
    }
    void helper(int& res, TreeNode* root, double target) {
        if (!root) return;
        if (abs(res - target) > abs(root->val - target)) res = root->val;
        if (target == root->val) {
            return;
        } else if (target > root->val) {
            helper(res, root->right, target);
        } else {
            helper(res, root->left, target);
        }
    }
};
