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
    void flatten(TreeNode* root) {
        vector<TreeNode*> stack;
        TreeNode* crt=root;
        while(crt){
            if(crt->right) stack.push_back(crt->right);
            crt->right=crt->left;
            crt->left=NULL;
            if(!crt->right){
                if(!stack.empty()) {
                    crt->right=stack[stack.size()-1];
                    stack.pop_back();
                }
            } 
            crt=crt->right;
        }  
    }
};
