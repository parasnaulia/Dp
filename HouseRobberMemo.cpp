#include <iostream>
using namespace std;
#include <climits>
#include <vector>
#include <algorithm>
int memoHouseRobber(vector<int> &nums, int n, vector<int> &dp)
{
      if (n == 0)
      {
            return nums[0];
      }
      if(n<0)
      {
            return 0;
      }
      if (dp[n] != -1)
      {
            return dp[n];
      }
      int take = nums[n] + memoHouseRobber(nums, n - 2, dp);
      int notTake = memoHouseRobber(nums, n - 1, dp);
      return dp[n] = max(take, notTake);
}
int main()
{
      vector<int> nums = {1, 2, 3, 4};
      vector<int> dp(nums.size(), -1);
      int n = nums.size() - 1;
      cout << "The maxi profit a robber can make is" << memoHouseRobber(nums, n, dp);
      return 0;
}

// this is my optimize code using dp
