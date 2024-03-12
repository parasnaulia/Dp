#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include<algorithm>
int main()
{

      string s1 = "paras";
      string s2 = "para";
      int n = s1.length();
      int m = s2.length();
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
      // Now we get dp
      // now we have to Shortest Common Subsequence
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
                  if (dp[n - 1][m] >= dp[n][m - 1])
                  {
                        ans += s1[n - 1];
                        n--;
                  }
                  else
                  {
                        ans += s2[m - 1];
                        m--;
                  }
            }
      }
      reverse(ans.begin(),ans.end());
      cout << ans << endl;
      return 0;
}