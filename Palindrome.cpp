#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <algorithm>
#include <limits>
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
      string s = "har";
      string s2 = s;
      reverse(s2.begin(), s2.end());
      int n = s.length();
      int m = s2.length();
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
      int ans = Lcs(s, s2, n, m, dp);
      cout << "The Longest Palindromic Subsequence is" << ans << endl;
      return 0;
}
