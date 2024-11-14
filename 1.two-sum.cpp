#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        map<int, vector<int>> mmap;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            mmap[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int first = i;

            mmap[nums[i]].pop_back();
            if (mmap[target - nums[i]].size() > 0)
            {
                int second = mmap[target - nums[i]][0];
                return {first, second};
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> n = {3, 2, 3};
    vector<int> sol = s.twoSum(n, 6);

    cout << sol[0] << " " << sol[1] << endl;
}