#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int Longest(vector<int> &nums, int prev, int index, vector<vector<int>> &dp)
{
      if (index == nums.size())
      {
            return 0;
      }
      if (dp[index][prev + 1] != -1)
      {
            return dp[index][prev + 1];
      }
      int take = INT_MIN;
      if (prev == -1 || nums[index] > nums[prev])
      {
            take = 1 + Longest(nums, index, index + 1, dp);
      }
      int notTake = Longest(nums, prev, index + 1, dp);
      return dp[index][prev + 1] = max(take, notTake);
}
int main()
{
      vector<int> nums = {5, 4, 11, 1, 16, 8};
      int n = nums.size();
      // int prev = -1;
      // vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
      //  int ans = Longest(nums, prev, 0, dp);

      // cout << ans << endl;

      // Write A bottom up dp
      vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

      for (int i = n - 1; i >= 0; i--)
      {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                  int take = 0;
                  if (prev == -1 || nums[i] > nums[prev])
                  {
                        take = 1 + dp[i + 1][i+1 ];
                  }
                  int notTake = dp[i + 1][prev + 1];
                  dp[i][prev + 1] = max(take, notTake);
            }
      }
      cout << "The Maximimum increwasing subsequence is" << dp[0][0] << endl;
      return 0;
}