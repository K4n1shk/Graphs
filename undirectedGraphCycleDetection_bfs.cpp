#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    bool dcycle(int src, int V, vector<int> &vis, vector<int> adj[])
    {
        queue<pair<int, int>> q;
        vis[src] = 1;
        q.push({src, -1});
        while (!q.empty())
        {
            int v = q.front().first;
            int par = q.front().second;
            q.pop();
            for (int u : adj[v])
            {
                if (!vis[u])
                {
                    vis[u] = true;
                    q.push({u, v});
                }
                else if (u != par)
                    return true;
            }
        }
        return false;
    }

public:
    //Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dcycle(i, V, vis, adj))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends