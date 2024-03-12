#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int knapSack(vector<int> &weight, vector<int> &value, int wt, int n, vector<vector<int>> &dp)
{
      if (n == 0)
      {
            return 0;
      }
      if (dp[n][wt] != -1)
      {
            return dp[n][wt];
      }
      int take = 0;
      if (weight[n - 1] <= wt)
      {
            take = value[n - 1] + knapSack(weight, value, wt - weight[n - 1], n - 1, dp);
      }
      int notTake = knapSack(weight, value, wt, n - 1, dp);
      return dp[n][wt] = max(take, notTake);
}
int main()
{
      vector<int> value = {10, 21, 12};
      vector<int> weight = {1, 2, 3};
      int n = value.size();
      int wt = 5;
      vector<vector<int>> dp(n + 1, vector<int>(wt + 1, 0));
      // Writting bottom up dp
      for (int i = 1; i <= n; i++)
      {
            for (int j = 1; j <= wt; j++)
            {
                  int take = 0;
                  if (weight[i - 1] <= wt)
                  {
                        take = value[i - 1] + dp[i - 1][j - weight[i - 1]];
                  }
                  int notTake = dp[i - 1][wt];
                  dp[i][j] = max(take, notTake);
            }
      }
      cout << "The maximum profit a chor can made" << dp[n][wt] << " ";

    //  cout << "The Maximum profit a chor can make" << knapSack(weight, value, wt, n, dp);
      return 0;
}