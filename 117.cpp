#include <iostream>
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
		//terminating condition
		if(root==NULL){
			return;
		}else if(root->left==NULL && root->right==NULL){
			return;
		}else{
			/*
			preorder processing
			1. point left child to right child if they exist.
			2. point left child or right child to neightbor's closest child, left or right child.
			*/
			TreeLinkNode* connectChild;
			if(root->right!=NULL){
				connectChild=root->right;
				if(root->left!=NULL){
					root->left->next=root->right;
				}
			}else{
				connectChild=root->left;
			}
			TreeLinkNode* movingRoot = root;
			while(movingRoot!=NULL){
				if(movingRoot->next==NULL){
					connectChild->next=NULL;
					break;
				}else{
					if(movingRoot->next->left!=NULL){
						connectChild->next=movingRoot->next->left;
						break;
					}else if(movingRoot->next->right!=NULL){
						connectChild->next=movingRoot->next->right;
						break;
					}else{
						movingRoot=movingRoot->next;
						cout << movingRoot->val << endl;
						//cout << movingRoot->next->val << endl;
					}
				}
			}
			connect(root->left);
			connect(root->right);
		}
	}
};


int main(int argc, char *argv[]) {
	Solution s;
	TreeLinkNode* n0 = new TreeLinkNode(0);
	TreeLinkNode* n1 = new TreeLinkNode(1);
	TreeLinkNode* n2 = new TreeLinkNode(2);
	TreeLinkNode* n3 = new TreeLinkNode(3);
	TreeLinkNode* n4 = new TreeLinkNode(4);
	TreeLinkNode* n5 = new TreeLinkNode(5);
	TreeLinkNode* n6 = new TreeLinkNode(6);
	TreeLinkNode* n7 = new TreeLinkNode(7);
	TreeLinkNode* n8 = new TreeLinkNode(8);
	TreeLinkNode* n9 = new TreeLinkNode(9);
	TreeLinkNode* n10= new TreeLinkNode(10);
	TreeLinkNode* n17= new TreeLinkNode(17);
	TreeLinkNode* n18= new TreeLinkNode(18);
	/*117 v1 failed in this test case because node4 is still not updated 
	during the recursive process for left subtree of node1
	*/
		/*
		2
		/ \
		1    3
		/ \  /  \
		0  7 9   4
		/  /\    /\
		5  6 10  8 18
		      \
              17
		*/

	n2->left  = n1;
	n2->right = n3;
	n1->left  = n0;
	n1->right = n7;
	n3->left  = n9;
	n3->right = n4;
	n0->left  = n5;
	n0->right = NULL;
	n7->left  = n6;
	n7->right = n10;
	n9->left  = NULL;
	n9->right = NULL;
	n4->left  = n8;
	n4->right = n18;
	n10->left  = NULL;
	n10->right = n17;
	
	s.connect(n2);
	system("pause");


	
}