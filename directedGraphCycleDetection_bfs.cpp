#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        queue<int> q;
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (int u : adj[i])
                indegree[u]++;
        }

        for (int i = 0; i < V; i++)
        {
            if (!indegree[i])
                q.push(i);
        }

        int count = 0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            count++;
            for (int u : adj[v])
            {
                indegree[u]--;
                if (!indegree[u])
                    q.push(u);
            }
        }
        if (count == V)
            return false;
        else
            return true;
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