#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(vector<vector<char>> &grid, int n, int m, int i, int j)
    {

        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1')
            return;

        grid[i][j] = 'O';
        dfs(grid, n, m, i + 1, j);     //down
        dfs(grid, n, m, i, j + 1);     //right
        dfs(grid, n, m, i - 1, j);     //top
        dfs(grid, n, m, i, j - 1);     //left
        dfs(grid, n, m, i + 1, j + 1); //South East
        dfs(grid, n, m, i + 1, j - 1); //South West
        dfs(grid, n, m, i - 1, j - 1); //North West
        dfs(grid, n, m, i - 1, j + 1); //North East
    }

public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, n, m, i, j);
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends