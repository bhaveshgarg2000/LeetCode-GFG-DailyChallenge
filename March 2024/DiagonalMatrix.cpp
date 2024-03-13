class Solution
{
public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        vector<int> ans;
        bool up = true;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i <= n + m - 1; i++)
        {
            if (up)
            {
                for (int j = 0; j <= i; j++)
                {
                    int row = i - j;
                    int col = j;
                    if (row < n && col < m)
                    {
                        ans.push_back(mat[row][col]);
                    }
                }
            }
            else
            {
                for (int j = 0; j <= i; j++)
                {
                    int row = j;
                    int col = i - j;
                    if (row < n && col < m)
                    {
                        ans.push_back(mat[row][col]);
                    }
                }
            }
            up = !up;
        }
        return ans;
    }
};