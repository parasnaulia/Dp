#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int main()
{

      vector<int> nums = {1, 2, 3, 5};
      int target = 0;
      for (int i = 0; i < nums.size(); i++)
      {
            target += nums[i];
      }
      int n = nums.size();
      if (target % 2 != 0)
      {
            cout << "Cant Be Partioned" << endl;
      }
      // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
      // cout << "The Target Sum is" << TargetSum(nums, target, nums.size(), dp);
      vector<vector<int>> dp(n + 1, vector<int>(target + 1, false));
      for (int i = 0; i <= n; i++)
      {
            dp[i][0] = true;
      }
      for (int i = 1; i <= n; i++)
      {
            for (int j = 1; j <= target; j++)
            {
                  int take = false;
                  if (j >= nums[i - 1])
                  {
                        take = dp[i - 1][j - nums[i - 1]];
                  }
                  int notTake = dp[i - 1][j];
                  dp[i][j] = take || notTake;
            }
      }
      int flag = 0;

      for (int i = 0; i <= target; i++)
      {
            if (dp[n][i])
            {
                  int p1 = i;
                  int p2 = target - i;
                  if (abs(p1 - p2) == 0)
                  {
                        cout << "The Partition Exist" << endl;
                        flag = 1;
                  }
            }
      }
      if (flag == 0)
      {
            cout << "Partition does not exist" << endl;
      }
      return 0;
}