class Solution
{
public:
    set<int> s;
    void findLevel(Node *root, int level)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL and root->right == NULL)
        {
            s.insert(level);
            return;
        }
        findLevel(root->left, level + 1);
        findLevel(root->right, level + 1);
    }
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        findLevel(root, 0);
        if (s.size() == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
        // Your code here
    }
};