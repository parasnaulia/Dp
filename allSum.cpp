#include <iostream>
using namespace std;
#include <climits>
#include <algorithm>
#include <vector>
void allSum(vector<int> &nums, int n, int target, vector<int> &v, vector<vector<int>> &ans, int i)
{
      if (target < 0)
      {
            return;
      }
      if (target == 0)
      {
            ans.push_back(v);
            return;
      }

      if (target > 0 && i <= n)
      {
            v.push_back(nums[i]);
            allSum(nums, n, target - nums[i], v, ans, i + 1);
            v.pop_back();
            allSum(nums, n, target, v, ans, i + 1);
      }
}
int main()
{
      vector<int> nums = {1, 2, 3, 4, 5};
      int target = 7;
      int n = nums.size() - 1;
      vector<int> v;
      int i = 0;
      vector<vector<int>> ans;
      allSum(nums, n, target, v, ans, i);
      for (int i = 0; i < ans.size(); i++)
      {
            for (int j = 0; j < ans[i].size(); j++)
            {
                  cout << ans[i][j] << " ";
            }
            cout << endl;
      }
      return 0;
}