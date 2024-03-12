#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int solve(vector<int> &nums, int Rsum)
{
    int i = 0;
    int j = 0;
    int ans = INT_MIN;
    int sum = 0;
    while (j < nums.size())
    {
        sum += nums[j];
        if (sum < Rsum)
        {
            j++;
        }
        else if (sum == Rsum)
        {
            ans = max(ans, (j - i + 1));
            j++;
        }
        else if (sum > Rsum)
        {
            while (sum > Rsum)
            {
                sum -= nums[i];
                i++;
            }
            if (sum == Rsum)
            {
                ans = max(ans, (j - i + 1));
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {2, 5, 7, 8, 9, 18, 2, 2};
    int Rsum = 14;
    int ans = solve(nums, Rsum);
    cout << "The maximum Size of window of Give Sum is: " << ans << endl;
    return 0;
}
