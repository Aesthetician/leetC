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
    int countNodes(TreeNode* root) {
      /**
      bruce force method: time exceeds!
      */
        queue<TreeNode*> q;
        int nSize=0;
        if(!root)return 0;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            nSize+=size;
            for(int i=0;i<size;i++){
                TreeNode* crt=q.front();
                if(crt->left) q.push(crt->left);
                if(crt->right)q.push(crt->right);
                q.pop();
            }
        }
        return nSize;
    }
};
