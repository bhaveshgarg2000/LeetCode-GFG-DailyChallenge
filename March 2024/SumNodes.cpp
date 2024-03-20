class Solution
{
public:
    int hight(Node *root)
    {
        if (root == NULL)
            return 0;
        return max(hight(root->left), hight(root->right)) + 1;
    }
    int sum = 0;
    void helper(Node *root, int h, int currVal)
    {
        if (!root)
            return;
        if (h == 1)
            sum = max(currVal + root->data, sum);
        if (root->left)
            helper(root->left, h - 1, currVal + root->data);
        if (root->right)
            helper(root->right, h - 1, currVal + root->data);
        return;
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        // code here
        int h = hight(root);
        helper(root, h, 0);
        return sum;
    }
};
