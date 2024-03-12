#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> lar(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    queue<int> q;
    vector<int> ans;
    while (j < nums.size())
    {
        if (q.empty() || nums[j] > q.back())
        {
            while (q.back() < nums[j] && !(q.empty()))
            {
                q.pop();
            }
            q.push(nums[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 >= k)
        {
            ans.push_back(q.front());
            if (q.front() == nums[i])
            {
                q.pop();
            }
            i++;
            j++
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 23, 11, 4, 1};
    int k = 3;
    vector<int> ans = lar(nums, k);
    cout << "the ans is" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}