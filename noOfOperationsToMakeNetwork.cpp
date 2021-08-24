#include <bits/stdc++.h>
using namespace std;

// Main Solution
class Solution
{

    void dfs(int v, vector<int> &visited, const vector<vector<int>> &adj)
    {
        visited[v] = 1;
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                dfs(u, visited, adj);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> visited(n + 1, 0);
        int count = 0;
        int sz = connections.size();
        if (n - 1 > sz)
            return -1;

        vector<vector<int>> adj(n);
        for (int i = 0; i < sz; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, visited, adj);
            }
        }
        return count - 1;
    }
};