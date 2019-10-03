// 543. Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        /*
           r0
          / 
         r
        / \
       p1 p2
       
       postorder traverse 
       1. update max path  
       2. return larger path length
        */
        int max_val = 0;
        postorder(root, max_val);
        return max_val;
    }
    int postorder(TreeNode* root, int& max_val) {
        if (!root) return 0;
        int pleft = postorder(root->left, max_val);
        int pright = postorder(root->right, max_val);
        max_val = max(max_val, pright + pleft);
        return (pleft >= pright) ? pleft + 1 : pright + 1;
        
    }
};
