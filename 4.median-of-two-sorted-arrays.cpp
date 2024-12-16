#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

/*
    Get median of the two arrays at hand
        if first is greater and second is smaller
            change thier lefts and rights to cover the area the that lies between the two medians

*/

// @lc code=start
class Solution
{
public:
    float getMedian(vector<int> &v, int left, int right)
    {
        if (left > right)
        {
            return 0;
        }

        if ((right - left + 1) % 2 == 0)
        {
            return (float)((v[left + (right - left + 1) / 2]) + (v[left + (right - left + 1) / 2 - 1])) / 2;
        }
        else
        {
            return (float)(v[left + (right - left) / 2]);
        }
    }

    int findIndexStartingFrom(vector<int> list, int left, int right, float num)
    {
        if (left > right)
        {
            if (list[right] > num)
            {
                return right;
            }
            else
            {
                return left;
            }
        }
        else
        {
            int mid = left + (right - left) / 2;

            if (list[mid] == num)
            {
                return mid;
            }
            else if (list[mid] < num)
            {
                return findIndexStartingFrom(list, mid + 1, right, num);
            }
            else
            {
                return findIndexStartingFrom(list, left, mid - 1, num);
            }
        }
    }

    int findIndexEndingFrom(vector<int> list, int left, int right, float num)
    {
        if (left > right)
        {
            if (list[left] > num)
            {
                return right;
            }
            else
            {
                return left;
            }
        }
        else
        {
            int mid = left + (right - left) / 2;

            if (list[mid] == num)
            {
                return mid;
            }
            else if (list[mid] < num)
            {
                return findIndexEndingFrom(list, mid + 1, right, num);
            }
            else
            {
                return findIndexEndingFrom(list, left, mid - 1, num);
            }
        }
    }

    float median2Arrays(vector<int> &array1, vector<int> &array2, int array1Left, int array1Right, int array2Left, int array2Right)
    {

        int m = array1Right - array1Left + 1;
        int n = array2Right - array2Left + 1;

        if (m + n <= 2)
        {
            int sum = 0;
            for (int i = array1Left; i <= array1Right; i++)
            {
                sum += array1[i];
            }

            for (int i = array2Left; i <= array2Right; i++)
            {
                sum += array2[i];
            }

            // Extract median from remaining list
            if (m + n == 2)
            {
                // cout << sum << " " << endl;
                return (float)(sum / 2);
            }
            else
            {
                return sum;
            }
        }
        else
        {
            float m1 = getMedian(array1, array1Left, array1Right);
            float m2 = getMedian(array2, array2Left, array2Right);

            if (m1 == 0)
            {
                m1 = m2;
            }

            if (m2 == 0)
            {
                m2 = m1;
            }

            if (m1 > m2)
            {
                swap(m1, m2);
            }

            return median2Arrays(array1, array2, findIndexStartingFrom(array1, array1Left, array1Right, m1), findIndexEndingFrom(array1, array1Left, array1Right, m2), findIndexStartingFrom(array2, array2Left, array2Right, m1), findIndexEndingFrom(array2, array2Left, array2Right, m2));
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        return median2Arrays(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1);
    }
};
// @lc code=end

int main()
{
    Solution s;

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    cout << "Median is " << s.findMedianSortedArrays(nums1, nums2) << endl;

    for (int i = 0; i < nums2.size(); i++)
    {
        nums1.push_back(nums2[i]);
    }

    sort(nums1.begin(), nums1.end());

    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    cout << "Median should be: " << s.getMedian(nums1, 0, nums1.size() - 1) << endl;
}