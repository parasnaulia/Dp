#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int MinOpertion(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
      if (n < 0)
      {
            return m;
      }
      if (m < 0)
      {
            return n;
      }
      if (dp[n][m] != -1)
      {
            return dp[n][m];
      }
      int insertion = 1 + MinOpertion(s1, s2, n, m - 1, dp);
      int Deletion = 1 + MinOpertion(s1, s2, n - 1, m, dp);
      int replace = 1 + MinOpertion(s1, s2, n - 1, m - 1, dp);
      return dp[n][m] = min(insertion, min(Deletion, replace));
}
int main()
{
      string s1 = "horse";
      string s2 = "ros";
      int n = s1.length();
      int m = s2.length();
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
      // Now I  have To minimimum no of opertions that is insertion del replace ;
      int ans = MinOpertion(s1, s2, n - 1, m - 1, dp);
      cout << ans << endl;
}