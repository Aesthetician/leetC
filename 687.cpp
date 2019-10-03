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
    /*
    recursively traverse nodes
    At each node, update max_value and return max of left and right path
    the node counts left path and right path if their node value are the same. 
    */
    int longestUnivaluePath(TreeNode* root) {
        int max_value=0;
        recursive_visit(root, max_value);
        return max_value;
    }
    
    int recursive_visit(TreeNode* root, int &max_value){
        if(!root) return 0;
        int left_value=recursive_visit(root->left, max_value);
        int right_value=recursive_visit(root->right, max_value);
        
        if(root->left && root->val==root->left->val) left_value++;
        else left_value=0;
        if(root->right && root->val==root->right->val) right_value++;
        else right_value=0;
       
        //update max_value
        max_value=max(max_value, left_value+right_value);
        
        return max(left_value, right_value);
        
    }
    
    
    
};
