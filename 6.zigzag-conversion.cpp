#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        string result = "";

        int length = s.length();
        int l = 2 * numRows - 2;

        if (numRows == 1)
        {
            return s;
        }
        else
        {
            for (int i = 0; i < numRows - 1; i++)
            {
                for (int j = 0; j < length + l; j += l)
                {
                    int m = j - i;
                    int n = j + i;
                    // cout << "j: " << j << endl;
                    // cout << "Checking " << s[m] << " and " << s[n] << endl;

                    if (m >= 0 && m < length)
                        result += s[m];

                    if (m != n)
                    {
                        if (n >= 0 && n < length)
                            result += s[n];
                    }
                }
            }
        }

        if (l % 2 == 0)
        {
            for (int i = l / 2; i < length; i += l)
            {
                result += s[i];
            }
        }

        return result;
    }
};
// @lc code=end

int main()
{
    Solution s;

    cout << s.convert("ABCDE", 4) << endl;
}