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
      int left = total_Path(grid, n - 1, m);
      int up = total_Path(grid, n, m - 1);
      int dg = total_Path(grid, n - 1, m - 1);
      return left + up + dg;
}
int main()
{
      vector<vector<int>> grid = {{1, 0, 1}, {1, 1, 1}, {1, 1, 1}};
      int ans = total_Path(grid, grid.size() - 1, grid[0].size() - 1);
      for (int i = 0; i < grid.size(); i++)
      {
            for (int j = 0; j < grid[i].size(); j++)
            {
                  cout << grid[i][j] << " ";
            }
            cout << endl;
      }
      cout << "The Total Number of Path will be" << ans << endl;
}