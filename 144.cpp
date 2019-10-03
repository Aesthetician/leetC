#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

/*
Use a stack to track the path.
When going forward, push the current root into the stack.
When going backward, pop out the end of the stack.
Also use a hash table to label the visit status.
*/

class Solution{
public:
	vector<int> preorderTraversal(TreeNode* root){
		vector<int> v;
		if (root==NULL)
		{
			return v;
		}
		else
		{
			return preorderTraversalMain(root);
		}
	}
	vector<int> preorderTraversalMain(TreeNode* root){
		vector<int> v;
		//use a stack to track the path
		vector<TreeNode*> stack;
		//a hash table to label the visits.
		unordered_map<TreeNode*, int> hashTable;
		//initialization 
		TreeNode* crtRoot = root;
		
		do
		{
			if (crtRoot == NULL)
			{
				//go backward
				crtRoot = stack[stack.size()-1];
			}
			else
			{
				//go forward
				/*
				preorder processing
				1. print value
				2. push crtRoot into stack
				3. update Hash table 
				*/
				//visit left child
				if (hashTable.count(crtRoot) == 0)
				{
					v.push_back(crtRoot->val);
					//cout << crtRoot->val;
					stack.push_back(crtRoot);
					hashTable.insert({ crtRoot, 0 });
					crtRoot = stack[stack.size() - 1]->left;
				}
				//visit right child
				else if (hashTable[stack[stack.size() - 1]] == 0)
				{
					crtRoot = stack[stack.size() - 1]->right;
					hashTable[stack[stack.size() - 1]] = 1;
				}
				//hashTable[stack.end()] ==1
				/*
				pop out stack
				go backward
				*/
				else 
				{
					stack.pop_back();
					if (stack.size() > 0)
					{
						crtRoot = stack[stack.size() - 1];
					}
				}
			}
		} while (!stack.empty());
	
		return v;
	}

};





int main(){
	
	Solution s300;
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
	vector<int> v = s300.preorderTraversal(n0);

	for (int i = 0; i <v.size(); i++)
	{
		//cout << i << endl;
		cout << v[i];
	}
	
	system("pause");
}

