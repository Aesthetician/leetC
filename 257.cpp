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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        helper(root, "", res);
        return res;
    }
    
    void helper(TreeNode* root, string path, vector<string>& res) {
        //keep the same shape
        path += "->" + to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(path.substr(2, path.size() - 2));
            return;
        } 
        if (root->left) helper(root->left, path, res);
        if (root->right) helper(root->right, path, res);
    }
};
