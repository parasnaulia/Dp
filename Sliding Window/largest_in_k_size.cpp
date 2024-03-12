#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <climits>
#include <queue>
vector<int> largest(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    queue<int> q;
    while (j < nums.size())
    {
        if (q.empty() || q.front() < nums[j])
        {
            while (q.front() < nums[j] && !(q.empty()))
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
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 3, 2, 5, 4, 2};
    int k = 3;
    vector<int> ans = largest(nums, k);
    cout << "The ans is " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0
}