/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 class Solution {
    private:
        pair<int, int> travel(TreeNode* root) {
            if (root == NULL) {
                return {0, 0};
            }
            auto left_node_choices = travel(root->left);
            auto right_node_choices = travel(root->right);
    
            int loot =
                root->val + left_node_choices.second + right_node_choices.second;
            int skip =
                std::max(left_node_choices.first, left_node_choices.second) +
                std::max(right_node_choices.first, right_node_choices.second);
    
            return {loot, skip};
        }
    
    public:
        int rob(TreeNode* root) {
            auto options = travel(root);
            return max(options.first, options.second);
        }
    };