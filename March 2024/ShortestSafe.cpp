class Node
{
public:
    int x;
    int y;
    int cnt;
};
class Solution
{
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {-1, 1, 0, 0};

    bool isSafe(int newX, int newY, int n, int m)
    {
        if (newX >= 0 && newY >= 0 && newX < n && newY < m)
            return true;

        return false;
    }

public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int newX = i + dr[k];
                        int newY = j + dc[k];

                        if (isSafe(newX, newY, n, m))
                        {
                            mat[newX][newY] = -1;
                        }
                    }
                }
            }
        }

        int ans = -1;

        queue<Node> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 1)
            {
                q.push({i, 0, 1});
            }
        }

        ans = INT_MAX;
        while (!q.empty())
        {
            // cout<<"hello"<<endl;
            int x = q.front().x;
            int y = q.front().y;
            int cnt = q.front().cnt;

            q.pop();
            if (y == m - 1)
            {
                ans = min(ans, cnt);
                continue;
            }

            vis[x][y] = true;

            for (int k = 0; k < 4; k++)
            {
                int newX = x + dr[k];
                int newY = y + dc[k];

                if (isSafe(newX, newY, n, m) && vis[newX][newY] == false && mat[newX][newY] == 1)
                {
                    q.push({newX, newY, cnt + 1});
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};