#include <iostream>
#include <vector>
using namespace std;

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

void printLCS(string s1, string s2, int n, int m)
{
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

      // Now Printing Longest LCS
      int i = n, j = m;
      string lcs;
      while (i > 0 && j > 0)
      {
            if (s1[i - 1] == s2[j - 1])
            {
                  lcs = s1[i - 1] + lcs;
                  i--;
                  j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                  i--;
            }
            else
            {
                  j--;
            }
      }

      cout << "The LCS is: " << lcs << endl;
}

int main()
{
      string s1 = "paras";
      string s2 = "pas";
      int n = s1.length();
      int m = s2.length();

      // Uncomment the following line for top-down approach
      // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
      // int ans = Lcs(s1, s2, n, m, dp);
      // cout << "The Longest common Subsequence is :" << ans << endl;

      // Now Writing Bottom-up dp and printing LCS
      printLCS(s1, s2, n, m);

      return 0;
}
