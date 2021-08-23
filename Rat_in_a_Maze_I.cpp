// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

    void allpath(vector<vector<int>> &m, int i, int j, int n, vector<string> &ans, string path)
    {
        if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] != 1)
            return;
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(path);
            return;
        }
        m[i][j] = -1;
        allpath(m, i + 1, j, n, ans, path + 'D');
        allpath(m, i - 1, j, n, ans, path + 'U');
        allpath(m, i, j + 1, n, ans, path + 'R');
        allpath(m, i, j - 1, n, ans, path + 'L');
        m[i][j] = 1;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        string s = "";
        allpath(m, 0, 0, n, ans, s);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends