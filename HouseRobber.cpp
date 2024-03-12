#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int houseRobber(vector<int> &nums, int n)
{
      if (n == 0)
      {
            return nums[0];
      }
      if (n < 0)
      {
            return 0;
      }
      int take = nums[n] + houseRobber(nums, n - 2);
      int notTake = houseRobber(nums, n - 1);
      return max(take, notTake);
}
int main()
{
      vector<int> nums = {1, 2, 3, 4, 5, 6};
      // in house robber we have to find the maximum profit and we have to not loot adject house
      int n = nums.size()-1;
      cout << "The amaximum profit that robber make" << houseRobber(nums, n) << endl;
      return 0;
}