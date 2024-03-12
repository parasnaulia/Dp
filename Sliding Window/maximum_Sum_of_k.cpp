#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int max_sum(vector<int> &nums, int k)
{
      // int n = nums.size();
      int maxi = INT_MIN;
      for (int i = 0; i < nums.size(); i++)
      {
            int sum = 0;
            int count = 1;
            sum += nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                  if (count == k)
                  {
                        break;
                  }
                  sum += nums[j];
                  count++;
            }
            maxi = max(sum, maxi);
      }
      return maxi;
}
int max_optimize(vector<int> &nums, int k)
{
      int i = 0;
      int j = 0;
      int sum = 0;
      int maxi = INT_MIN;
      while (j < nums.size())
      {
            sum += nums[j];
            if (j - i + 1 == k)
            {
                  maxi = max(maxi, sum);
                  sum = sum - nums[i];
                  i++;
            }
            j++;
      }
      return maxi;
}
int main()
{
      vector<int> nums = {1, 2, 3, 4, 5, 6, 6};
      int k = 3;
      // int ans = max_sum(nums, k);
      int ans = max_optimize(nums, 3);
      cout << ans << endl;
}
