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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > v;
        if(root==NULL){
            return v;
        }else{
            return zigzag(root);
        }
    }
    
    vector<vector<int>>zigzag(TreeNode* root){
        vector<vector<int>> v;
        vector<TreeNode*> crt;
        crt.push_back(root);
        int flip=0;
        while(!crt.empty()){
            vector<TreeNode*> next;
            vector<int> level;
            for(int i=0;i<crt.size();i++){
                if(flip%2==0){
                    level.push_back(crt[i]->val);
                }else{
                    level.push_back(crt[crt.size()-1-i]->val);
                }
                if(crt[i]->left!=NULL){
                    next.push_back(crt[i]->left);
                }
                if(crt[i]->right!=NULL){
                    next.push_back(crt[i]->right);                        
                }
            }
            flip++;
            crt = next;
            v.push_back(level);
        }
        return v;
    } 
    
};
