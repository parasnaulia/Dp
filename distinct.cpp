#include <iostream>
#include <vector>
using namespace std;
#include <climits>
int distinct(string s1, string s2, int n, int m,vector<vector<int>> &dp)
{
       if (m < 0)
      {
            return 1;
      }

      if (n < 0)
      {
            return 0;
      }
      if(dp[n][m]!=-1)
      {
            return dp[n][m];
      }
     

      if (s1[n] == s2[m])
      {
            return dp[n][m]=  distinct(s1, s2, n - 1, m - 1,dp) + distinct(s1, s2, n - 1, m,dp);
      }
      return dp[n][m]= distinct(s1, s2, n - 1, m,dp);
}
int main()
{
      string s1 = "rabbbit";
      string s2 = "rabbit";
      int n = s1.length();
      int m = s2.length();
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      int ans = distinct(s1, s2, n - 1, m - 1,dp);
      cout << ans << endl;
      return 0;
}
