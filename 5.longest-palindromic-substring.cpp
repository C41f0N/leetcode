#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

/*
    Traversing over the string, with incrementing i 0.5 each time
    this makes the program land between numbers too, makes it account for both even and odd palindromes.

    then we can keep two pointers, one that goes to the right, and other to the left, step size being 1.
    the left one can be cieled and right one floored

    the pointers will keep moving, the distance between them will expand as long as the
    values on the right and left pointers is the same.

    Once this condition breaks, these values of left and right pointers will be stored if their distance is
    greater than the ones recorded before.

*/

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int length = s.length();
        int finalLeft = 0;
        int finalRight = 0;
        for (float i = 0; i < length; i += 0.5)
        {
            int left = ceil(i - 1), right = floor(i + 1);
            while (left >= 0 && right < length)
            {
                if (s[left] != s[right])
                {
                    left++;
                    right--;

                    if (left > i || right < i)
                    {
                        left += 0;
                        right += 0;
                    }

                    break;
                }

                if (right - left > finalRight - finalLeft)
                {

                    finalLeft = left;
                    finalRight = right;
                }

                left--;
                right++;
            }
        }

        return s.substr(finalLeft, finalRight - finalLeft + 1);
    }
};
// @lc code=end

int main()
{
    Solution s;

    cout << s.longestPalindrome("babad") << endl;
}