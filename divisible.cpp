#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int longest(vector<int> &nums, int prev, int index, vector<vector<int>> &dp)
{
      if (index > nums.size())
      {
            return 0;
      }
      if (dp[index][prev+1] != -1)
      {
            return dp[index][prev+1];
      }

      int take = 0;
      if (prev == -1 || (nums[prev] < nums[index] && nums[index] % nums[prev] == 0))
      {
            return 1 + longest(nums, index, index + 1, dp);
      }
      int notTake = longest(nums, prev, index + 1, dp);
      return dp[index][prev+1] = max(take, notTake);
}
int main()
{
      vector<int> nums = {1, 2, 3, 5, 6, 7, 8,16,24,48};
      int n=nums.size();
      // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));

      // int ans = longest(nums, -1, 0, dp);

      // cout << "The ans is " << ans << endl;
      vector<vector<int>> dp(n+1,vector<int> (n+1,0));
      for(int i=n-1;i>=0;i--)
      {
            for(int prev=i-1;prev>=-1;prev--)
            {
                  
            }
      }
}