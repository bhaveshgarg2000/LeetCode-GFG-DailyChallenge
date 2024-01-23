vector<int> findOrder(int n, int m, vector<vector<int>> vv)
{
    // code here
    vector<int> indeg(n, 0);
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
        adj[vv[i][1]].push_back(vv[i][0]);

    for (auto v : vv)
        indeg[v[0]]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);

    vector<int> res, vis(n, false);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (auto v : adj[u])
        {
            indeg[v]--;
            if (indeg[v] == 0 && !vis[v])
            {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    if (res.size() != n)
        return {};
    return res;
}