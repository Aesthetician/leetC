/*
987. Vertical Order Traversal of a Binary Tree
@ 8.14.2019
ref:
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/260502/C++-BFSDFS
https://zxi.mytechroad.com/blog/tree/leetcode-987-vertical-order-traversal-of-a-binary-tree/
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/231113/C++-hashmap-vs.-map
*/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, unordered_map<int, set<int>>> hmap;
        int x_min = INT_MAX, x_max = INT_MIN, y_max = 0;
        dfs(root, x_min, x_max, y_max, 0, 0, hmap);
        vector<vector<int>> res;
        for (int x = x_min; x <= x_max; x++) {
            if (hmap.count(x) == 0) continue;
            res.push_back(vector<int> ());
            for (int y = 0; y <= y_max; y++) {
                if (hmap[x].count(y) == 0) continue;
                for (auto it = hmap[x][y].begin(); it != hmap[x][y].end(); ++it) {
                    res.back().push_back(*it);
                }
            }
        }
        return res;
    }
    void dfs(TreeNode* root, int &x_min, int &x_max, int &y_max, int x, int y, unordered_map<int, unordered_map<int, set<int>>> &hmap) {
        if (!root) return;
        hmap[x][y].insert(root->val);
        x_min = min(x_min, x);
        x_max = max(x_max, x);
        y_max = max(y_max, y);
        dfs(root->left, x_min, x_max, y_max, x - 1, y + 1, hmap);
        dfs(root->right, x_min, x_max, y_max, x + 1, y + 1, hmap);
    }
};

