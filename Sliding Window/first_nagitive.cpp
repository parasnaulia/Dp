#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <queue>
// #include <bits/stdc++.h>

vector<int> second_queue(vector<int> &nums, int k)
{

      int i = 0;
      int j = 0;
      vector<int> ans;
      queue<int> q;
      while (j < nums.size())
      {
            if (nums[j] < 0)
            {
                  q.push(nums[j]);
            }
            if (j - i + 1 < k)
            {
                  j++;
            }
            else if (j - i + 1 >= k)
            {
                  if (q.size() > 0)
                  {
                        ans.push_back(q.front());
                        if (nums[i] == q.front())
                        {
                              q.pop();
                              i++;
                        }
                        else
                        {
                              
                              i++;
                        }
                  }
                  else
                  {
                        ans.push_back(0);
                        i++;
                  }

                  j++;
            }
      }
      return ans;
}
vector<int> first_nagitive(vector<int> &nums, int k)
{
      int i = 0;
      int j = 0;
      bool flag = true;
      vector<int> ans;
      while (j < nums.size())
      {
            if (flag == true && nums[j] < 0)
            {
                  ans.push_back(nums[j]);
                  flag = false;
            }
            if (j - i + 1 >= k)
            {
                  if (flag == true)
                  {
                        ans.push_back(0);
                  }
                  i++;
                  flag = true;
            }
            j++;
      }
      return ans;
}
int main()
{
      vector<int> nums = {12, -1, -7, 8, -15, 30, 16, 28};
      // vector<int> ans= first_nagitive(nums, 3);
      vector<int> ans = second_queue(nums, 3);
      // cout << ans << endl;
      cout << "The array of first nagitive number" << endl;
      for (int i = 0; i < ans.size(); i++)
      {
            cout << ans[i] << " ";
      }
      return 0;
}