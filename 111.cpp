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
	int minDepth(TreeNode* root) {
		//terminating condition
		if(root==NULL){
			return 0;
		}else if(root->left==NULL && root->right==NULL){
			return 1;
		}else{
			return getminDepth(root);
		}
	}
	int getminDepth(TreeNode* root) {
		//terminating condition
		if(root==NULL){
			return 0;
		}else{
			int left =getminDepth(root->left);
			int right=getminDepth(root->right);
			if(left>0 && 0<right){
				if(left<right){
					return left+1;
				}else{
					return right+1;
				}
			}else{
				if(left>right){
					return left+1;
				}else{
					return right+1;
				}
			}
		}
	}
};