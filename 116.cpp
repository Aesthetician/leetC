/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        //terminating condition
        if(root==NULL){
            return;
        }else if(root->left==NULL && root->right==NULL){
            return;
        }else{//branching condition
            /*preorder processing, 
            1.point the left child to right child 
            2. point the right child to neighbor's left chiild
            */
            root->left->next=root->right;
            if(root->next!=NULL){
                root->right->next=root->next->left;
            }else{
                root->right->next=NULL;
            }
            connect(root->left);
            connect(root->right);     
        }
    }
};
