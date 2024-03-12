#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int Buy(vector<int> &nums, int i, int w, int buy)
{
      if (i == nums.size())
      {
            return 0;
      }
      int profit = 0;
      if (buy && w <= 2 && w > 0)
      {
            profit = max(-nums[i] + Buy(nums, i + 1, w, !buy), Buy(nums, i + 1, w, buy));
      }
      else if (w <= 2 && w > 0)
      {
            profit = max(nums[i] + Buy(nums, i + 1, w - 1, !buy), Buy(nums, i + 1, w, buy));
      }
      return profit;
}
int main()
{
      vector<int> nums = {7, 1, 5, 3, 6, 4};
      int n = nums.size();
      // here W ecan only perform two Transaction
      // But Remember first you have to sell Before buying
      // You cannot buy more than two products
      int ans = Buy(nums, 0, 2, true);
      cout << "The Maximum Profit By Seeling the stock" <<ans<< endl;
      return 0;
}