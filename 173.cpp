/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
use a stack to track the in-order path. When the current smallest is report, check its right subtree. If the right subtree exists, store its DFS path into stack. 

|_|->right subtree
|_|
|_|
|_|
stack
*/
class BSTIterator {
    vector<TreeNode*> stack;
public:
    BSTIterator(TreeNode *root) {
        if(root){
            TreeNode* crt = root;
            while(crt){
                stack.push_back(crt);
                crt=crt->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(stack.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        int res=0;
        if(hasNext()){
            res = stack[stack.size()-1]->val;
            if(stack[stack.size()-1]->right){
                TreeNode* crt=stack[stack.size()-1]->right;
                stack.pop_back();
                while(crt){
                    stack.push_back(crt);
                    crt=crt->left;
                }
            }else{
                stack.pop_back();
            }
        }
        
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
