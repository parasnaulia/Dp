#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int solve(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    int maxi = INT_MIN;
    unordered_map<int, int> umap;
    while (j < nums.size())
    {
        umap[nums[j]]++;
        if (umap.size() <= k)
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
            if (umap.size() == 2)
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
    vector<int> nums = {0, 1, 2, 2};
    int k = 2;
    int ans = solve(nums, k);
    cout << "The ans is " << ans << endl;
    return 0;
}