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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        /*
        for the case where only one node is the deepest node, what should we do? 
        Ans: return itself.
        two pass
        1. find max depth
        2. return LCA of the nodes with max depth
        */
        int max_val = max_depth(root);
        return lca(root, 0, max_val);
    }
    int max_depth(TreeNode* root) {
        if (!root) return -1;
        return max(max_depth(root->left), max_depth(root->right)) + 1;
    }
    TreeNode* lca(TreeNode* root, int dis, int max_val) {
        if (!root) return NULL;
        if (dis == max_val) return root;
        TreeNode* left = lca(root->left, dis + 1, max_val);
        TreeNode* right = lca(root->right, dis + 1, max_val);
        if (left && right) return root;
        if (left) return left;
        if (right) return right;
        return NULL;
    }
    
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        /*
        one pass:
        LCA: return <max depth, node>
        Ex:
                   3<3,2>
               /            \
             5<3,2>           1<2,1>
          /     \           /    \
        6<2,6>    2<3,2>  0<2,0> 8<2,8>
               /    \
              7<3,7> 4<3,4>
        
        */
        pair<int, TreeNode*> subtree = lca(root, 0);
        return subtree.second;
    }
    pair<int, TreeNode*> lca(TreeNode* root, int dis) {
        if (!root) return {dis, NULL};
        pair<int, TreeNode*> left = lca(root->left, dis + 1);
        pair<int, TreeNode*> right= lca(root->right,dis + 1);
        if (left.first == right.first) return {left.first, root};
        if (left.first > right.first) return left;
        else return right;
    }
};
