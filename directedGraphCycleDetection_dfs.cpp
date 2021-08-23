#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    bool dcycle(int v, vector<int> adj[], vector<int> &vis, vector<int> &revdfs)
    {
        vis[v] = 1;
        revdfs[v] = 1;
        for (int u : adj[v])
        {
            if (!vis[u])
            {
                if (dcycle(u, adj, vis, revdfs))
                    return true;
            }
            else if (revdfs[u])
                return true;
        }
        revdfs[v] = 0;
        return false;
    }

public:
    //Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V, 0);
        vector<int> revdfs(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dcycle(i, adj, vis, revdfs))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends