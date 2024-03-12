#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int buy2(vector<int> &nums, int n, bool buy, vector<vector<int>> &dp)
{
      if (n == nums.size())
      {
            return 0;
      }
      if (dp[n][buy] != -1)
      {
            return dp[n][buy];
      }
      int profit = 0;
      if (buy)
      {
            profit = max(-nums[n] + buy2(nums, n + 1, !buy, dp), buy2(nums, n + 1, buy, dp));
      }
      else
      {
            profit = max(nums[n] + buy2(nums, n + 1, !buy, dp), buy2(nums, n + 1, buy, dp));
      }
      return dp[n][buy] = profit;
}
int main()
{
      vector<int> nums = {7, 1, 5, 3, 6, 4};
      int n = nums.size();
      bool buy = 1;
      vector<vector<int>> dp(n + 1, vector<int>(2, -1));
      int ans = buy2(nums, 0, buy, dp);
      cout << "The maximum profit you can make is :" << ans << endl;
      return 0;
}