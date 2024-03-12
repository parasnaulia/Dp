#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <climits>
int main()
{
    string s = "a";
    string t = "a";

    // return s;
    int i = 0;
    int j = 0;
    unordered_map<char, int> umap;
    for (auto c : t)
    {
        umap[c]++;
    }
    int mini = INT_MAX;
    int idx1 = -1;
    int idx2 = -1;
    int count = umap.size();
    while (j < s.length())
    {
        if (umap.find(s[j]) != umap.end())
        {
            umap[s[j]]--;
            if (umap[s[j]] == 0)
            {
                count--;
            }
        }
        if (count > 0)
        {
            j++;
        }
        else if (count == 0)
        {
            // mini=min(mini,(j-i+1));
            if (mini > (j - i + 1))
            {
                mini = j - i + 1;
                idx1 = i;
                idx2 = j;
            }
            while (count == 0)
            {
                if (umap.find(s[i]) != umap.end())
                {
                    umap[s[i]]++;
                    if (umap[s[i]] == 1)
                    {
                        count++;
                    }
                }

                if (mini > (j - i + 1))
                {
                    mini = j - i + 1;
                    idx1 = i;
                    idx2 = j;
                }
                i++;
            }
            j++;
        }
    }
    string ans = "";
    if (idx1 == -1 && idx2 == -1)
    {
        cout << "The Minimum String is"
             << " " << endl;
    }
    else
    {

        for (int i = idx1; i <= idx2; i++)
        {
            ans += s[i];
        }
    }
    cout << "The Minimum Window is " << endl;
    cout << ans << endl;
}
// This is a Code Written By Paras Naulia and it is a problem of sliding window