#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int TotatargetSum(vector<int> &nums, int target, int n, vector<vector<int>> &dp)
{
      if (n == 0)
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
      if (target >= nums[n - 1])
      {
            take = TotatargetSum(nums, target - nums[n - 1], n - 1, dp);
      }
      int notTake = TotatargetSum(nums, target, n - 1, dp);
      return dp[n][target] = take + notTake;
}
int main()
{
      vector<int> nums = {1, 2, 3, 4, 5};
      int target = 5;
      int n = nums.size();
      vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
      // writing the bottom up dp
      for (int i = 0; i <= n; i++)
      {
            dp[i][0] = 1;
      }
      for (int i = 1; i <= n; i++)
      {
            for (int j = 1; j <= target; j++)
            {
                  int take = 0;
                  if (j >= nums[i - 1])
                  {
                        take = dp[i - 1][j - nums[i - 1]];
                  }
                  int notTake = dp[i - 1][j];
                  dp[i][j] = take + notTake;
            }
      }
      cout << "The Number of Subset Possible is " << dp[n][target] << " ";

      //  cout << "The  Total sum is" << TotatargetSum(nums, target, n , dp);
      return 0;
}
