#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <map>
#include <bits/stdc++.h>
int anagrams(string s1, string s2)
{
      unordered_map<char, int> umap;
      for (int i = 0; i < s2.length(); i++)
      {
            umap[s2[i]]++;
      }
      int i = 0;
      int j = 0;
      int count = umap.size();
      // vector<int> ans;
      int ans = 0;
      int k = s2.length();
      while (j < s1.length())
      {
            if (umap.find(s1[j]) != umap.end())
            {
                  umap[s1[j]]--;
                  if (umap[s1[j]] == 0)
                  {
                        count--;
                  }
            }
            if (j - i + 1 < k)
            {
                  j++;
            }
            else if (j - i + 1 >= k)
            {
                  if (count == 0)
                  {
                        ans++;
                  }
                  if (umap.find(s1[i]) != umap.end())
                  {
                        umap[s1[i]]++;
                        if (umap[s1[i]] == 1)
                        {
                              count++;
                        }
                        
                  }
                  i++;
                  j++;
            }
      }
      return ans;
}
int main()
{
      string s1 = "forxxofrcvfor";
      string s2 = "for";
      int ans = anagrams(s1, s2);
      cout << "The Total ansgrams is " << ans << endl;
      return 0;
}




// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int anagrams(string s1, string s2)
// {
//     unordered_map<char, int> umap;
    
//     for (int i = 0; i < s2.length(); i++)
//     {
//         umap[s2[i]]++;
//     }
    
//     int i = 0;
//     int j = 0;
//     int count = umap.size();
//     int ans = 0;
    
//     while (j < s1.length())
//     {
//         if (umap.find(s1[j]) != umap.end())
//         {
//             umap[s1[j]]--;
//             if (umap[s1[j]] == 0)
//             {
//                 count--;
//             }
//         }
        
//         if (j - i + 1 < s2.length())
//         {
//             j++;
//         }
//         else if (j - i + 1 == s2.length())
//         {
//             if (count == 0)
//             {
//                 ans++;
//             }
            
//             if (umap.find(s1[i]) != umap.end())
//             {
//                 umap[s1[i]]++;
//                 if (umap[s1[i]] == 1)
//                 {
//                     count++;
//                 }
//             }
            
//             i++;
//             j++;
//         }
//     }
    
//     return ans;
// }

// int main()
// {
//     string s1 = "forxxofrcvfor";
//     string s2 = "for";
    
//     int ans = anagrams(s1, s2);
//     cout << "The Total anagrams is " << ans << endl;
    
//     return 0;
// }
