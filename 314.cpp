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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 0));
        vector<vector<int>> res_left;
        vector<vector<int>> res_right;
        while (!que.empty()) {
            int sz = que.size();
            for (int i = 0; i < sz; ++i) {
                pair<TreeNode*, int> crt = que.front();
                que.pop();
                if (crt.first->left) {
                    que.push(make_pair(crt.first->left, crt.second - 1));
                }
                if (crt.first->right) {
                    que.push(make_pair(crt.first->right, crt.second + 1));
                }
                vector<vector<int>>* vptr;
                if (crt.second < 1) {
                    vptr = &res_left;
                } else {
                    vptr = &res_right;
                }
                while (vptr->size() < abs(crt.second) + 1) vptr->push_back(vector<int> ());
                vptr->at(abs(crt.second)).push_back(crt.first->val);
            }
        }
        //merge
        int nleft = res_left.size();
        for (int i = nleft - 1; i > -1; --i) {
            res.push_back(res_left[i]);
        }
        int nright = res_right.size();
        for (int i = 1; i < nright; ++i) {
            res.push_back(res_right[i]);
        }
        return res;
    }
};
