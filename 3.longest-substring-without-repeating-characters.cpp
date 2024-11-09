#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        vector<int> characters(128, -1);
        int longestLength = 0, length = s.length(), currentLength = 0;

        for (int i = 0; i < length; i++)
        {
            if (characters[s[i]] != -1)
            {
                if (currentLength > longestLength)
                    longestLength = currentLength;

                currentLength = 0;
                i = characters[s[i]];
                fill(characters.begin(), characters.end(), -1);
            }
            else
            {
                currentLength++;
                characters[s[i]] = i;
            }
        }
        longestLength = max(longestLength, currentLength);
        return longestLength;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("dvdf") << endl;
}