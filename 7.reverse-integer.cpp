#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
public:
    long int reverse(long int x)
    {
        long int xx = x;

        bool sign = x < 0;

        string max = "2147483647"; // 2^31 - 1 = 2147483647
        string min = "2147483648"; // - 2^31 = -2147483648
        string s = "";

        if (x == -2147483648)
        {
            return 0;
        }

        // cout << xx << endl;
        if (xx == 0)
        {
            s = "0";
        }
        else
        {

            while (xx)
            {
                if (sign)
                {
                    s += (xx % 10) * -1 + '0';
                }
                else
                {
                    s += (xx % 10) + '0';
                }
                xx /= 10;
            }
        }

        if (sign)
        {
            // The number should be lesser than or equal to 4294967296
            if (s.length() == 10)
            {
                // Compare
                for (int i = 0; i < 10; i++)
                {
                    if (s[i] < min[i])
                    {
                        break;
                    }
                    else if (s[i] > min[i])
                    {
                        return 0;
                    }
                }
            }
            else if (s.length() > 10)
            {
                return 0;
            }
        }
        else
        {
            // The number should be lesser than or equal to 4294967295
            if (s.length() == 10)
            {
                // Compare
                for (int i = 0; i < 10; i++)
                {
                    if (s[i] < max[i])
                    {
                        break;
                    }
                    else if (s[i] > max[i])
                    {
                        return 0;
                    }
                }
            }
            else if (s.length() > 10)
            {
                return 0;
            }
        }

        // cout << s << endl;

        long int res = 0;
        // Converting string back to int
        for (int i = 0; i < s.length(); i++)
        {
            if (sign)
            {
                res -= (s[i] - '0') * pow(10, s.length() - 1 - i);
            }
            else
            {
                res += (s[i] - '0') * pow(10, s.length() - 1 - i);
            }
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;

    cout << s.reverse(4294967224) << endl;
}
