/*
124. Binary Tree Maximum Path Sum
*/
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
    int maxPathSum(TreeNode* root) {
        /*
        clarifying Q: 
        1. the nodes might be with negative value. 
        2. the path is with one node at least. 
        
        approach: 
        1. visit the tree by postorder
        2. consider the left and rigth path
            a. the path from left subtree to right subtree
            b. the path from left subtree or right subtree to the parent of the current node
            c. skip the path with negative sum
        
        pseudo-code:
        resursive fun () {
            //terminating condition
            if root == null, return 0;
            //to do task
            left = max(0, func(root->left))
            right= max(0, func(root->right))
            max_val = max(max_val, left+right+root->val)
            //return stage
            return max(left, right) + root->val
        }
        
        test case:
        
         -10
         / \
        9  20
          /  \
         -15  -7
        node, -15: (0,0) return -15; max = -15
        node, -7:  (0,0) return -7; max = -7
        node, 20: (-15,-7) return 20, max = 20
        node, -10: (9,20) return 10, max = 19
        
        corner case:
        1. single node 
        
        -10
        ans = -10
        
        2. tree with the same value
            -10
            /  \
         -10  -10
         ans = -10
        */
        int max_val = INT_MIN;
        helper(root, max_val);
        return max_val;
    }
    int helper (TreeNode* root, int &max_val) {
        if (!root) return 0;
        int left = max(0, helper(root->left, max_val));
        int right = max(0, helper(root->right, max_val));
        max_val = max(max_val, left + right + root->val);
        return max(left, right) + root->val;
        
    }
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        /*
        postorder 
        1. find the sum at the subroot: n[root] + n[left] + n[right]
        2. return the maximal sum of one branch, left or right.
        -10
        / \
       9  20   --> 1. sum = 20+15+7; 2. return 20+15
         /  \
        15   7
        
        notice: negative sum of the path!
        */
        int max_val = INT_MIN;
        postorder(root, max_val);
        return max_val;
    }
    
    int postorder(TreeNode* root, int& max_val) {
        if(!root) return 0;
        int left = max(0, postorder(root->left, max_val));
        int right = max(0, postorder(root->right, max_val));
        int sum = root->val + left + right;
        max_val = max(max_val, sum);
        return max(left, right) + root->val;
    }
};
