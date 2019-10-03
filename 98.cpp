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
    pre < current 
    */
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return inorder(root, pre);
    }
    bool inorder(TreeNode* root, TreeNode* &pre) {
        if (!root) return true;
        if(!inorder(root->left, pre)) return false;
        if (pre && pre->val >= root->val) return false;
        pre = root;
        if(!inorder(root->right, pre)) return false;
        else return true;
    }
};

//bad version
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
    bool isValidBST(TreeNode* root) {
        long long int crt_max = LLONG_MIN;
        if(!root) return true;
        if(!root->left && !root->right) return true;
        return inorder(root, crt_max); 
    }
    
    bool inorder(TreeNode* root, long long int &crt_max){
        if(!root) return true;
        
        if(!inorder(root->left, crt_max)) return false; 
        if(root->val > crt_max) crt_max = root->val; 
        else return false;
        if(!inorder(root->right, crt_max)) return false;
        
        return true;
    }
};
