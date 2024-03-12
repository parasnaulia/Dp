#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int total_Path(vector<vector<int>> &grid, int n, int m)
{
      if (n == 0 && m == 0)
      {
            return 1;
      }
      if (n < 0 || m < 0 || grid[n][m] == 0)
      {
            return 0;
      }
      int up = total_Path(grid, n - 1, m);
      int left = total_Path(grid, n, m - 1);

      return up + left;
}
int main()
{
      vector<vector<int>> grid = {{1, 1, 1},
                                  {1, 1, 1},
                                  {1, 1, 1}

      };
      int n = grid.size();
      int m = grid[0].size();

      int ans = total_Path(grid, n - 1, m - 1);
      for (int i = 0; i < grid.size(); i++)
      {
            for (int j = 0; j < grid[i].size(); j++)
            {
                  cout << grid[i][j] << " ";
            }
            cout << endl;
      }
      cout << "The Total Number of Paths Possible is" << ans << endl;
      return 0;
}