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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        else      return inOrderKthSmallest(root, k);
    }
    
    int inOrderKthSmallest(TreeNode* root, int& k){
        //terminating condition
        if(!root->left && !root->right){
            if(k--==0) return root->val;
            else       return 0;
        }else{
            int left=0;
            if(root->left) left = inOrderKthSmallest(root->left, k);
            if(k==0) return left;
            //in order search
            k--;
            if(k==0) return root->val;
            //search right subtree
            if(root->right) return inOrderKthSmallest(root->right, k);
            return 0;
        }//branching condition
    }
};
