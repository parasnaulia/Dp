#include <iostream>
using namespace std;
#include <climits>
#include <algorithm>
#include <vector>
void subset(vector<int> &nums, int n, vector<int> &v, vector<vector<int>> &ans, int i)
{
      if (i > n)
      {
            ans.push_back(v);
            return;
      }
      v.push_back(nums[i]);
      subset(nums, n, v, ans, i + 1);
      v.pop_back();
      subset(nums, n, v, ans, i + 1);
}
int main()
{
      vector<int> v;
      vector<vector<int>> ans;
      vector<int> nums = {1, 2, 3, 4};
      int n = nums.size()-1;
      int i = 0;
      subset(nums, n, v, ans, i);
      cout << "The subset are" << endl;
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
//Finally dohe
