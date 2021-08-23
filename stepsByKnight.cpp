#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Code here
        int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int x1 = KnightPos[0] - 1;
        int y1 = KnightPos[1] - 1;

        vector<vector<bool>> vis(N, vector<bool>(N, false));
        queue<pair<int, int>> q;

        q.push({x1, y1});
        vis[x1][y1] = true;
        int moves = 0;
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == (TargetPos[0] - 1) && y == (TargetPos[1] - 1))
                    return moves;

                for (int j = 0; j < 8; j++)
                {
                    int newx = x + dx[j];
                    int newy = y + dy[j];

                    if (newx >= 0 && newy >= 0 && newx < N && newy < N && !vis[newx][newy])
                    {
                        vis[newx][newy] = true;
                        q.push({newx, newy});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends