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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int n = nums.size();
        TreeNode* root = preorder(0, n - 1, nums);
        return root;
    }
    
    TreeNode* preorder(int i, int j, vector<int> &nums){
        if(i == j) return new TreeNode(nums[i]);
        
        int mid = i + (j - i) / 2;
        TreeNode* n = new TreeNode(nums[mid]);
        
        if(mid - 1 >= i) n->left = preorder(i, mid - 1, nums);
        if(mid + 1 <= j) n->right= preorder(mid + 1, j, nums);
    
        return n;
        
    }
};
