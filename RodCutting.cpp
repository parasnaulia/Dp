#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#include <math.h>
int RodCut(vector<int> &nums, vector<int> weight, int amount, int n, vector<vector<int>> &dp)
{
      if (n == 0 || amount <= 0)
      {
            return (amount / weight[0]) * nums[0];
      }
      if (dp[n - 1][amount] != -1)
      {
            return dp[n][amount];
      }
      int take = 0;
      if (weight[n - 1] <= amount)
      {
            take = nums[n - 1] + RodCut(nums, weight, amount - weight[n - 1], n, dp);
      }
      int notTake = RodCut(nums, weight, amount, n - 1, dp);
      return dp[n - 1][amount] = max(take, notTake);
}

int main()
{
      vector<int> nums = {3, 5, 8, 9, 10, 17, 17, 20};
      int amount = nums.size();
      vector<int> weight(amount, 0);
      vector<vector<int>> dp(amount, vector<int>(amount + 1, -1));
      for (int i = 0; i < nums.size(); i++)
      {
            weight[i] = i + 1;
      }
      int ans = RodCut(nums, weight, amount, nums.size(), dp);
      cout << "The Max profit is" << ans << endl;
      return 0;
}
// Finally Done bhai
// Congratulationsss
