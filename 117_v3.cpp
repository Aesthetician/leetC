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
        TreeLinkNode* start=root;
    
        while(start){
            TreeLinkNode* crt;
            crt=start;
            TreeLinkNode* connectingNode=crt->left;
            while(crt){
                if(start==crt){ 
                    if(crt->left)
                        start=crt->left;
                    else
                        start=crt->right;//start = NULL if crt has no child
                }
                
                //deal with connection
                if(crt->right){
                    if(connectingNode)connectingNode->next=crt->right;
                    connectingNode=crt->right;
                }
                
                if(crt->next){
                    if(crt->next->left){
                        if(connectingNode)connectingNode->next=crt->next->left;
                        connectingNode=crt->next->left;
                    }
                }
                
                crt=crt->next;
                if(!start) start=crt;    
        
            }        
        }
    }

};
