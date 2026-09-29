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
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* result = root;
        if (root == NULL) {
            return 0;
        }
        if (root != NULL) {
            if (root->val < low) {
                result = trimBST(root->right, low, high);
            } else if (root->val > high) {
                result = trimBST(root->left, low, high);
            } else {
                root->left = trimBST(root->left, low, high);
                root->right = trimBST(root->right, low, high);
                result = root;
            }
        }
        return result;
    }
};