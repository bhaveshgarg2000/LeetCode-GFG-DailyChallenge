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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v;
        inOrderTrav(root,v);
        return balance(0,v.size()-1,v);
    }

private:
    void inOrderTrav(TreeNode* root, vector<TreeNode*>& v) {
        if (root == NULL) {
            return;
        }
        inOrderTrav(root->left, v);
        v.push_back(root);
        inOrderTrav(root->right, v);
    }
    TreeNode* balance(int start, int end, vector<TreeNode*>& v) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        v[mid]->left = balance(start, mid - 1, v);
        v[mid]->right = balance(mid + 1, end, v);
        return v[mid];
    }
};