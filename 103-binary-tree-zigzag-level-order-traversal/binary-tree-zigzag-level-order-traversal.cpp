/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> pq;
        pq.push(root);
        bool leftToRight = true;

        while (!pq.empty()) {
            int n = pq.size();
            vector<int> row(n);

            for (int i = 0; i < n; ++i) {
                TreeNode* node = pq.front();
                pq.pop();

                int idx = leftToRight ? i : n - 1 - i;
                row[idx] = node->val;

                if (node->left) {
                    pq.push(node->left);
                }
                if (node->right) {
                    pq.push(node->right);
                }
            }

            ans.push_back(row);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
