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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        queue<int> qid;
        
        q.push(root);
        qid.push(0);
        TreeNode* crt;
        int max_val = 1;
        int level = 1;
        int next_level;
        int left = 0;
        int right = 0;
        int crt_idx = 0;
        
        while(!q.empty()){
            for(int i = 0; i < level; i++){
                crt = q.front();
                q.pop();
                if(i == 0) left = qid.front();
                if(i == level -1) right = qid.front();
                crt_idx = qid.front();
                qid.pop();
                if(crt->left){
                    q.push(crt->left);
                    qid.push(2 * crt_idx);
                    next_level++;
                }
                if(crt->right){
                    q.push(crt->right);
                    qid.push(2 * crt_idx + 1);
                    next_level++;
                }
            }
            if(level > 1) max_val = max(max_val, right - left + 1);
            level = next_level;
            next_level = 0;
        }
        
        return max_val;
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
    int widthOfBinaryTree(TreeNode* root) {
        int max_val = 0;
        vector<pair<int, int>> v;

        preorder(root, 0, 0, max_val, v);
        return max_val;
    }

    void preorder(TreeNode* root, int depth, int idx, int &max_val, vector<pair<int, int>> &v){
        if(!root) return;

        if(depth > v.size() - 1 || v.empty()) v.push_back(make_pair(idx, idx));
        else v[depth].second = idx;

        max_val = max(max_val, v[depth].second - v[depth].first + 1);

        if(root->left)  preorder(root->left, depth + 1, idx * 2, max_val, v);
        if(root->right) preorder(root->right, depth + 1, idx * 2 + 1, max_val, v);
    }
};
