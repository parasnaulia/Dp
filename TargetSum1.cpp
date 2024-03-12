#include <iostream>
using namespace std;
#include <vector>
#include <climits>
bool TargetSum(vector<int> &nums, int target, int n, vector<vector<int>> &dp)
{
      if (n == 0)
      {
            if (target == 0)
            {
                  return true;
            }
            return false;
      }
      if (dp[n][target] != -1)
      {
            return dp[n][target];
      }
      int take = false;
      if (target >= nums[n - 1])
      {
            take = TargetSum(nums, target - nums[n - 1], n - 1, dp);
      }
      int notTake = TargetSum(nums, target, n - 1, dp);
      return dp[n][target] = take || notTake;
}
int main()
{
      vector<int> nums = {1, 2, 3};
      int target = 5;
      int n = nums.size();
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
      cout << "The Target Sum Possible is" << dp[n][target] << " ";

      return 0;
}
