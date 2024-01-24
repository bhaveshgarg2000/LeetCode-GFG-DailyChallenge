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
private:
    // Helper function to recursively count pseudo-palindromic paths
    void count_pseudo(TreeNode *root, vector<int>& n, int &count) {
        if (root == NULL) {
            return;
        }

        // Increment the count for the current node's value
        n[root->val]++;

        // Recursively process the left and right subtrees
        count_pseudo(root->left, n, count);
        count_pseudo(root->right, n, count);

        // Check if the current node is a leaf node
        if (root->left == NULL and root->right == NULL) {
            int flag = 0;

            // Check the frequency of each digit (1 to 9)
            for (int i = 1; i <= 9; i++) {
                if (n[i] % 2 != 0) {
                    flag++;
                }
            }

            // If there is at most one odd frequency, it's a pseudo-palindromic path
            if (flag == 0 || flag == 1) {
                count++;
            }
        }

        // Decrement the count for the current node's value after processing
        n[root->val]--;
    } 

public:
    // Main function to calculate the number of pseudo-palindromic paths
    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;
        // Array to store the frequency of each digit (1 to 9)
        vector<int> n(10, 0);
        count_pseudo(root, n, count);  
        return count;
    }
};
