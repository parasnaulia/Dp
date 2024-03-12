#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int TotatargetSum(vector<int> &nums, int target, int n, vector<vector<int>> &dp)
{
      if (n < 0)
      {
            if (target == 0)
            {
                  return 1;
            }
            return 0;
      }
      if (dp[n][target] != -1)
      {
            return dp[n][target];
      }
      int take = 0;
      if (nums[n] <= target)
      {
            take = TotatargetSum(nums, target - nums[n], n, dp);
      }
      int notTake = TotatargetSum(nums, target, n - 1, dp);
      return dp[n][target] = take + notTake;
}
int main()
{
      vector<int> nums = {1, 2, 3, 4, 5};
      int target = 5;
      int n = nums.size();
      // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
      //  Now Writing the memo code
      // cout << "The Total number of Target possible is" << TotatargetSum(nums, target, n, dp) << endl;
      // Writting bottom up dp
      vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
      for (int i = 0; i <= n; i++)
      {
            dp[i][0] = 1;
      }
      for (int i = 1; i <= n; i++)
      {
            for (int j = 1; j <= target; j++)
            {
                  int take = 0;
                  if (nums[i - 1] <= j)
                  {
                        take = dp[i][j - nums[i - 1]];
                  }
                  int notTake = dp[i - 1][j];
                  dp[i][j] = take + notTake;
            }
      }
      cout << "The Total Number of number of taget sum is" << dp[n][target] << endl;
      return 0;
}