#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int solve(string nums, int k)
{
    unordered_map<char, int> umap;
    int i = 0;
    int j = 0;
    int maxi = INT_MIN;
    while (j < nums.length())
    {
        umap[nums[j]]++;
        if (umap.size() < k)
        {
            j++;
        }
        else if (umap.size() == k)
        {
            maxi = max(maxi, (j - i + 1));
            j++;
        }
        else
        {
            while (umap.size() > k)
            {
                umap[nums[i]]--;
                if (umap[nums[i]] == 0)
                {
                    umap.erase(nums[i]);
                }
                i++;
            }
            if (umap.size() == k)
            {
                maxi = max(maxi, (j - i + 1));
            }
            j++;
        }
    }
    return maxi;
}
int main()
{
    string s1 = "xxxxxxforxxforrrr";
    int k = 3;
    int ans = solve(s1, k);
    cout << "The ans is " << ans << endl;
    return 0;
}
