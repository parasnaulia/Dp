#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int Triangular_Path_Sum(vector<vector<int>> &grid, int i, int j, int size)
{
      if (i == size)
      {
            return grid[i][j];
      }

      int down = grid[i][j] + Triangular_Path_Sum(grid, i + 1, j, size);
      int right = grid[i][j] + Triangular_Path_Sum(grid, i + 1, j + 1, size);
      return min(down, right);
}
int main()
{
      vector<vector<int>> grid = {{1}, {1, 2}, {1, 2, 3}, {7, 2, 3, 4}};
      int i = 0;
      int j = 0;
      int size1 = grid.size() - 1;
      int ans = Triangular_Path_Sum(grid, i, j, size1);
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