#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    int Count(vector<int> &nums, int s1)
{
    int n = nums.size();
    int count[n + 1][s1 + 1];
    count[0][0] = 1;
    for (int i = 1; i < s1 + 1; i++)
    {
        count[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < s1 + 1; j++)
        {
            count[i][j] = (nums[i - 1] > j) ? count[i - 1][j] : count[i - 1][j] + count[i - 1][j - nums[i - 1]];
        }
    }
    return count[n][s1];
}
    
    int findTargetSumWays(vector<int>& nums, int target) {
         int sum = 0;
    for (int x : nums)
        sum += x;
    if (abs(target) > sum)
    {
        return 0;
    }
    int s1 = (sum + target) / 2;
    int ans = Count(nums, s1);
    return ans;
    }
};
int main() {
    Solution S;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    cout << S.findTargetSumWays(nums, target);
    return 0;
}