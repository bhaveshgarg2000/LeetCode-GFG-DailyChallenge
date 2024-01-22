class Solution
{
private:
    void dfs(Node *root, int sum, int curr, vector<int> temp, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        curr += root->key;
        temp.push_back(root->key);

        if (curr == sum)
            ans.push_back(temp);
        dfs(root->left, sum, curr, temp, ans);
        dfs(root->right, sum, curr, temp, ans);
    }

public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, sum, 0, temp, ans);
        return ans;
    }
};