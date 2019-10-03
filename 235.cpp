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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //corner condition
        if(p==q){
            return p;
        }else{
            return inOrderCheck(root, p, q);
        }
    }
    
    TreeNode* inOrderCheck(TreeNode* root, TreeNode* p, TreeNode* q){
        //terminating condition
       if(root==p || root==q){//find p,q or one of p,q are the root, and the other is in its subtree. 
           return root;
       }else if (root==NULL){
           return NULL;
       }else{
           TreeNode* left = inOrderCheck(root->left, p, q);
           TreeNode* right= inOrderCheck(root->right, p, q);
           if(left!=NULL && right!=NULL){
               return root;
           }else if(left!=NULL){
               return left;
           }else if (right!=NULL){
               return right;
           }else{
               return NULL;
           }
       }//branching condition
    }
};

