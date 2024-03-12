#include <iostream>
using namespace std;
#include <limits>
#include <algorithm>
#include <vector>
#include <set>
void dSubset(vector<int> &nums, int n, vector<int> &v, set<set<int>> &ans, int i)
{
      if (i > n)
      {
            set<int> subset;
            for (int i = 0; i < v.size(); i++)
            {
                  subset.insert(v[i]);
            }
            // Convert vector to set
            ans.insert(subset);
            return;
      }
      v.push_back(nums[i]);
      dSubset(nums, n, v, ans, i + 1);
      v.pop_back();
      dSubset(nums, n, v, ans, i + 1);
}
int main()
{
      vector<int> nums = {1, 2, 3, 4};
      int n = nums.size() - 1;
      vector<int> v;
      set<set<int>> ans;
      int i = 0;
      dSubset(nums, n, v, ans, i);
      for (const auto &subset : ans)
      {
            for (const auto &element : subset)
            {
                  cout << element << " ";
            }
            cout << endl;
      }
}