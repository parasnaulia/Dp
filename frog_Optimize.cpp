#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int jump(int n, vector<int> &v,vector<int> &dp)
{
      if (n == 0)
      {
           return 0;
      }
      if (n < 0)
      {
            return INT_MAX;
      }
      if(dp[n]!=-1)
      {
            return dp[n];
      }
      int jump1 = jump(n - 1, v,dp) + abs(v[n] - v[n - 1]);
      int jump2 = INT_MAX;

      if (n > 1)
      {
            jump2 = jump(n - 2, v,dp) + abs(v[n] = v[n - 2]);
      }
      return  dp[n]=min(jump1,jump2);
}
int main()
{
      int n = 6;
      vector<int> v = {30, 10, 60, 10, 60, 50};
      vector<int> dp(n+1,-1);
      int ans = jump(n - 1, v,dp);
      cout << "The ans is" << ans << endl;
}