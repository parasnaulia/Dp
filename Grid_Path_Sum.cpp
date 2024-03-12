#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <algorithm>
int total_PathSum(vector<vector<int>> grid, int n, int m, vector<vector<int>> &dp)
{
      if (n == 0 && m == 0)
      {
            return grid[0][0];
      }
      if (n < 0 || m < 0)
      {
            return 1e8;
      }
      if (dp[n][m] != -1)
      {
            return dp[n][m];
      }
      int left = grid[n][m] + total_PathSum(grid, n - 1, m, dp);
      int up = grid[n][m] + total_PathSum(grid, n, m - 1, dp);
      return dp[n][m] = min(left, up);
}

int main()
{
      vector<vector<int>> grid = {{1, 3, 4}, {2, 34, 4}, {1, 2, 34}};
      int n = grid.size() - 1;
      int m = grid[0].size() - 1;
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
      int ans = total_PathSum(grid, n, m, dp);
      for (int i = 0; i < grid.size(); i++)
      {
            for (int j = 0; j < grid[i].size(); j++)
            {
                  cout << grid[i][j] << " ";
            }
            cout << endl;
      }
      cout << "The Minimum Path Sum is" << ans << endl;
      return 0;
}
