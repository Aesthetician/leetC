#include <iostream>

using namespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x):val(x),left(NULL), right(NULL){}
};

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
	vector<vector<int> > pathSum(TreeNode* root, int sum) {
		vector<vector<int> > v;
		if(root==NULL){
			return v;
		}else{
			return levelByLevel(root, sum);
		}
	}
	vector<vector<int> > levelByLevel(TreeNode* root, int sum){
		/*
		crt: a vector of point to store next level nodes
		path: a vector of int to record the path 
		*/
		vector<TreeNode*> crt;
		vector<vector<int> > path;
		vector<vector<int> > v;
		crt.push_back(root);
		vector<int> v0;
		v0.push_back(root->val);
		path.push_back(v0);
		while(true){
			vector<TreeNode*> next;
			vector<vector<int> > nextPath;
			for(int i=0;i<crt.size();i++){
				path[i].push_back(crt[i]->val);
				if(crt[i]->left!=NULL){
					nextPath.push_back(path[i]);
					next.push_back(crt[i]->left);
				}
				if(crt[i]->right!=NULL){
					nextPath.push_back(path[i]);
					next.push_back(crt[i]->right);
				}
			}
			crt = next;
			if(crt.empty()){
				break;
			}else{
				path=nextPath;
			}
		}
		for(int i=0;i<path.size();i++){
			int pathSum=0;
			for(int k=0;k<path[i].size();k++){
				pathSum+=path[i][k];
			}
			if(pathSum==sum){
				v.push_back(path[i]);
			}
		}
		return v;
	}
};


int main(int argc, char *argv[]) {
	Solution s;
	TreeNode* n0 = new TreeNode(0);
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	
		/*
		0
		/ \
		1    2
		/ \  /  \
		3  4  5  6
		/
		7
		*/

	n0->left = n1;
	n0->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;
	n3->left = n7;
	n3->right = NULL;
	cout << s.pathSum(n0, 11) << "\n";
	system("pause");

}