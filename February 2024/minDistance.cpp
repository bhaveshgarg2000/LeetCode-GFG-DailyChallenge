class Solution
{
public:
    map<int, vector<int>> mp;

    /* Should return minimum distance between a and b
    in a tree with given root*/
    void makegraph(Node *root)
    {
        if (root == NULL)
            return;
        if (root->left)
        {
            mp[root->data].push_back(root->left->data);
            mp[root->left->data].push_back(root->data);
        }
        if (root->right)
        {
            mp[root->data].push_back(root->right->data);
            mp[root->right->data].push_back(root->data);
        }
        makegraph(root->left);
        makegraph(root->right);
    }
    int findDist(Node *root, int a, int b)
    {
        // Your code here
        makegraph(root);
        map<int, int> dis;
        dis[a] = 0;
        queue<int> q;
        q.push(a);
        while (!q.empty())
        {
            int y = q.front();
            q.pop();
            for (auto x : mp[y])
            {
                if (x != a && dis[x] == 0)
                {
                    dis[x] = dis[y] + 1;
                    q.push(x);
                }
            }
        }
        return dis[b];
    }
};
