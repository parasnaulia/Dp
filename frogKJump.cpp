// #include <iostream>
// using namespace std;
// #include <bits/stdc++.h>
// int frogK(vector<int> &nums, int n, int k)
// {
//       if (n == 0)
//       {
//             return 0;
//       }
//       if (n < 0)
//       {
//             return INT_MAX;
//       }
//       int maxi = INT_MAX;
//       for (int i = 1; i <= k; i++)
//       {
//             int ans = frogK(nums, n - i, k) + abs(nums[n] - nums[n - i]);
//             maxi = min(maxi, ans);
//       }
//       return maxi;
// }
// int main()
// {
//       vector<int> nums = {1, 2, 3, 4};
//       int n = 4;
//       int ans = frogK(nums, n, 3);
//       cout << ans << endl;
//       return 0;
// }

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int frogK(vector<int> &nums, int n, int k)
{
      if (n <= 0)
      {
            return 0;
      }
     
      int maxi = INT_MAX;
      for (int i = 1; i <= k; i++)
      {
            int ans = frogK(nums, n - i, k) + abs(nums[n] - nums[n - i]);
            maxi = min(maxi, ans);
      }
      return maxi;
}

int main()
{
      vector<int> nums = {1, 2, 3, 40};
      int n = 4;
      int ans = frogK(nums, n - 1, 3); // Adjusting the index to match array indexing
      cout << ans << endl;
      return 0;
}
