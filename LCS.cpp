#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <algorithm>
#include <limits>
// #include <bits/stdc++.h>
int Lcs(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
      if (n == 0 || m == 0)
      {
            return 0;
      }
      if (dp[n][m] != -1)
      {
            return dp[n][m];
      }
      if (s1[n - 1] == s2[m - 1])
      {
            return dp[n][m] = 1 + Lcs(s1, s2, n - 1, m - 1, dp);
      }
      return dp[n][m] = max(Lcs(s1, s2, n - 1, m, dp), Lcs(s1, s2, n, m - 1, dp));
}
int main()
{
      string s1 = "paras";
      string s2 = "pas";
      int n = s1.length();
      int m = s2.length();
      // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
      // int ans = Lcs(s1, s2, n, m, dp);
      // cout << "The Longest common Subsequence is :" << ans << endl;
      //  Now Writting Bottom up dp
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
      for (int i = 1; i <= n; i++)
      {
            for (int j = 1; j <= m; j++)
            {
                  if (s1[i - 1] == s2[j - 1])
                  {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                  }
                  else
                  {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                  }
            }
      }

      cout << "The Lcs using Bottom up approach" << dp[n][m] << " " << endl;

      // Dp will look like this
      // for (int i = 0; i <= n; i++)
      // {
      //       for (int j = 0; j <= m; j++)
      //       {
      //             cout << dp[i][j] << " ";
      //       }
      //       cout << endl;
      // }

      // Now Printing Longest lCs
      string ans = "";
      while (n > 0 || m > 0)
      {
            if (s1[n - 1] == s2[m - 1])
            {
                  ans += s1[n - 1];
                  n--;
                  m--;
            }
            else
            {
                  if (dp[n][m - 1] >= dp[n - 1][m])
                  {
                        m--;
                  }
                  else
                  {
                        n--;
                  }
            }
      }
      reverse(ans.begin(), ans.end());
      cout << "The Lcs is " << ans << endl;

      return 0;
}