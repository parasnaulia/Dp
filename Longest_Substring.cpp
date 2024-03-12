#include <iostream>
using namespace std;
#include <vector>
int LCS(string s1, string s2, int n, int m)
{
      if (n < 0 || m < 0)
      {
            return 0;
      }
      if (s1[n] == s2[m])
      {
            return 1 + LCS(s1, s2, n - 1, m - 1);
      }
      return 0;
}
int main()
{
      string s1 = "paras";
      string s2 = "paras";
      int maxi = -1;
      for (int i = 0; i < s1.length(); i++)
      {
            for (int j = 0; j < s2.length(); j++)
            {
                  maxi = max(maxi, LCS(s1, s2, i, j));
            }
      }
      cout << "The Longest Common Substring is" << maxi << endl;
      return 0;
}