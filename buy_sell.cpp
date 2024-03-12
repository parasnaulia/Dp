#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
      vector<int> nums = {7, 1, 4, 5, 6};
      // Applying brute force approach
      int n = nums.size();
      // int maxi = -1e7;
      // for (int i = 0; i < nums.size(); i++)
      // {
      //       for (int j = i + 1; j < n; j++)
      //       {
      //             maxi = max(maxi, nums[j] - nums[i]);
      //       }
      // }
      // cout << "The Maximum Profit Buy Selling a Stock is " << maxi << endl;
      int profit = 0;
      int mini = INT_MAX;
      for (int i = 0; i < nums.size(); i++)
      {
            mini = min(mini, nums[i]);
            profit = max(profit, nums[i] - mini);
      }
      cout << "the Maimum Profit one can make is " << profit << endl;
      return 0;
}