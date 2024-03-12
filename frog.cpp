#include <iostream>
using namespace std;

#include<bits/stdc++.h>
int jump(int n, vector<int> &v)
{
      if (n == 0)
      {
           return 0;
      }
      if (n < 0)
      {
            return INT_MAX;
      }
      int jump1 = jump(n - 1, v) + abs(v[n] - v[n - 1]);
      int jump2 = INT_MAX;

      if (n > 1)
      {
            jump2 = jump(n - 2, v) + abs(v[n] = v[n - 2]);
      }
      return min(jump1,jump2);
}
int main()
{
      int n = 6;
      vector<int> v = {30, 10, 60, 10, 60, 50};
      int ans = jump(n - 1, v);
      cout << "The ans is" << ans << endl;
}