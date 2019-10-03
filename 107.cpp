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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if(root==NULL){
            return result;
        }else{
            return levelByLevel(root);
        }
    }
        
    vector<vector<int> > levelByLevel(TreeNode* root){
        vector<vector<int> > result;
        vector<TreeNode*> crt;
        crt.push_back(root);
        while(!crt.empty()){
            vector<TreeNode*> next; 
            vector<int> level;
            for(int i=0;i<crt.size();i++){
                //store current level into matrix
                level.push_back(crt[i]->val);
                
                //store pointer of next level nodes
                if(crt[i]->left!=NULL){
                    next.push_back(crt[i]->left);
                }
                if(crt[i]->right!=NULL){
                    next.push_back(crt[i]->right);
                }
            }
            crt = next;
            //store the result of each level in fron of the vector
            result.insert(result.begin(),level);
        }
        return result;
    }    
    
};
