class Solution
{
public:
    /*You are required to complete below method */
    int sumOfLeafNodes(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (root->left == NULL and root->right == NULL)
        {
            return root->data;
        }
        return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
    }
};