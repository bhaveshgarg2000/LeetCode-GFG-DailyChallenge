
class Solution
{
public:
    int minValue(Node *root)
    {
        int minV = root->data;
        while (root != NULL)
        {
            minV = min(minV, root->data);
            root = root->left;
        }
        return minV;
    }
};