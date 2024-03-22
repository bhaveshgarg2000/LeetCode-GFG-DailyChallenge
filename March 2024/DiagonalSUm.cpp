class Solution
{
public:
    vector<int> diagonalSum(Node *root)
    {
        vector<int> diagonalSums;
        if (root == nullptr)
            return diagonalSums;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            int sum = 0;
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                while (curr != nullptr)
                {
                    sum += curr->data;
                    if (curr->left != nullptr)
                    {
                        q.push(curr->left);
                    }
                    curr = curr->right;
                }
            }
            diagonalSums.push_back(sum);
        }

        return diagonalSums;
    }
};