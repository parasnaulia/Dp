#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <bits/stdc++.h>

// int knapSack(vector<int> &weight,vector<int> &values,int wt,int n)
// {

// }

// int main()
// {
//       vector<int> values={10,21,12,12};
//       vector<int> weight={2,1,4,8};
//       int wt=5;
//       int n=weight.size()-1;
//       knapSack(weight,values,wt,n);

// }
int main()
{

      int M = 10;
      vector<int> B = {6, 3, 2};
      vector<int> A = {15, 4, 1};

      std::unordered_map<int, int> umap;
      int paras = M;

      for (int i = 0; i < 3; i++)
      {
            umap[A[i] - B[i]] = i;
      }

      // Copy the elements of the unordered_map to a vector
      std::vector<std::pair<int, int>> sortedMap(umap.begin(), umap.end());

      // Sort the vector based on the keys
      std::sort(sortedMap.begin(), sortedMap.end(), [](const auto &a, const auto &b)
                { return a.first > b.first; });

      int ans = 0;
      for (const auto &x : sortedMap)
      {
            if (x.first <= 0 && M < B[x.second])
            {
                  continue;
            }
            if (M == 0)
            {
                  break;
            }

            int pp = (M / B[x.second]);
            ans += pp * A[x.second];
            M = M - pp;
      }

      //cout << ans;
      for (auto x : sortedMap)
      {
            cout << x.first << " " << x.second << endl;
      }
}