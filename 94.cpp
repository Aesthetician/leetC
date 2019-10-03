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
    vector<int> inorderTraversal(TreeNode* root) {
        /*
        1. stack to store left most and use stack top to get back to the parent 
        2. turn right to move on.
        1
         \
          2
         / 
        3
        ex:
            root
           /
        l1
        /  \
        l2  r2
          \
           r1
        
        stk: rt,l1,l2
        
        */
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> stk;
        TreeNode* crt = root;
        while(crt || !stk.empty()) {
            while (crt) {
                stk.push(crt);
                crt = crt->left;
            }
            if (!stk.empty()) {
                res.push_back(stk.top()->val); // inorder process
                crt = stk.top()->right;
                stk.pop();
            }
        }
        return res;
    }
};
