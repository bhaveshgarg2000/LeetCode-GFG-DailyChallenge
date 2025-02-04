//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool detectCycle(int i, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[i] = true;
        queue<pair<int, int>> q;
        q.push({i, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (int x : adj[node])
            {
                if (!vis[x])
                {
                    vis[x] = 1;
                    q.push({x, node});
                }
                else if (x != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        // Code here
        int n = adj.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (detectCycle(i, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends