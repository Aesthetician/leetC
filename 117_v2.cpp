#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for binary tree with next pointer.
*/
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		//use iteration to build the next pointer
		vector<TreeLinkNode*> crt;
		if(root==NULL){
			return;
		}else{
			crt.push_back(root);
		}
		while(!crt.empty()){
			vector<TreeLinkNode*> nextLayer;
			//deal with node layer by layer
			cout << "crtsize:" << crt.size() << endl;
			for(int i=0;i<crt.size();i++){
				/*if left child exists, puch its pointer into the vector of next layer pointers
				and set the connecting node as the left child default
				*/	
				cout << crt[i]->val << endl;
				TreeLinkNode* connectingNode=NULL;//mistake: forget to initilize it!
				if(crt[i]->left!=NULL){
					nextLayer.push_back(crt[i]->left);
					connectingNode=crt[i]->left;
				}
				/*if right child exists, 
				1.push its pointer into the vector of next layer pointers
				2.update the connecting node as the right child 
				3.build the next pointer of the left child if it exists. 
				*/
				if(crt[i]->right!=NULL){
					nextLayer.push_back(crt[i]->right);
					connectingNode=crt[i]->right;
					if(crt[i]->left!=NULL){
						crt[i]->left->next=crt[i]->right;
					}
				}
				/*current root helps its child to connect to the next neighbor
				1. if the left child of the root's neighbor exists, make the root's child connect to it.
				2. if not, check the right child of the root's neighbor.
				3. if the children of the root's neighbor don't exit, shift the neighbor as new root
				*/
				if(connectingNode!=NULL){
					TreeLinkNode* crtRoot=crt[i];
					while(crtRoot!=NULL){
						if(crtRoot->next==NULL){
							connectingNode->next=NULL;
							cout << "cc:" << connectingNode->val << endl;
							break;
						}else{
							if(crtRoot->next->left!=NULL){
								connectingNode->next=crtRoot->next->left;
								break;
							}else if(crtRoot->next->right!=NULL){
								connectingNode->next=crtRoot->next->right;
								break;
							}else{
								crtRoot=crtRoot->next;
							}
						}
					}
				}
			}
			crt=nextLayer;
		}
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	TreeLinkNode* n3 = new TreeLinkNode(3);
	TreeLinkNode* n7 = new TreeLinkNode(7);
	TreeLinkNode* n9 = new TreeLinkNode(9);
	TreeLinkNode* n15= new TreeLinkNode(15);
	TreeLinkNode* n20= new TreeLinkNode(20);
		
		/*
		3
		/ \
		9  20
		  /  \
         15   7
	    */

	n3->left  = n9;
	n3->right = n20;
	n9->left  = NULL;
	n9->right = NULL;
	n20->left  = n15;
	n20->right = n7;
		
	s.connect(n3);
	system("pause");


	
}