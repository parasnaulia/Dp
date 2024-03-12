// k = 2, prices = [2,4,1]
// op 2
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int Buy(vector<int> &nums, int buy, int k, int i, int count, vector<vector<vector<int>>> &dp)
{
      if (i == nums.size())
      {
            return 0;
      }
      if (dp[i][buy][count] != -1)
      {
            return dp[i][buy][count];
      }
      if (buy && count <= k && count > 0)
      {
            return dp[i][buy][count] = max(-nums[i] + Buy(nums, !buy, k, i + 1, count, dp), Buy(nums, buy, k, i + 1, count, dp));
      }
      else if (count <= k && count > 0)
      {
            return dp[i][buy][count] = max(nums[i] + Buy(nums, !buy, k, i + 1, count--, dp), Buy(nums, buy, k, i + 1, count, dp));
      }
}
int main()
{
      vector<int> nums = {3, 2, 6, 5, 0, 3};
      int n = nums.size();
      int k = 2;
      vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
      int ans = Buy(nums, true, k, 0, k, dp);
      cout << "The max Profit You can make is" << ans << endl;
      return 0;
}