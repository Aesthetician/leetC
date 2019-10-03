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
    bool hasPathSum(TreeNode* root, int sum) {
        return  traversePathSum(root, 0, sum);
    }
    
    bool traversePathSum(TreeNode* root, int sum, int targetSum){
        //terminating condition: leaf node
        if(root==NULL){
            return false;
        }else if(root->left==NULL && root->right==NULL){
            if(sum+root->val==targetSum){
                return true;
            }else{
                return false;
            }
        }else{
            return traversePathSum(root->left, sum+root->val, targetSum)+
                traversePathSum(root->right, sum+root->val, targetSum);
        }
        //branching condition
    }
};
