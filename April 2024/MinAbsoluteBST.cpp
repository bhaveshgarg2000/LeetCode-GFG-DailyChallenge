class Solution
{
    void util(Node *root, int &mini, int &prev)
    {
        if (root == NULL)
        {
            return;
        }
        util(root->left, mini, prev);
        mini = min(mini, abs(prev - root->data));
        prev = root->data;
        util(root->right, mini, prev);
    }

public:
    int absolute_diff(Node *root)
    {
        int mini = INT_MAX;
        int prev = INT_MAX / 2;
        util(root, mini, prev);
        return mini;
    }
};