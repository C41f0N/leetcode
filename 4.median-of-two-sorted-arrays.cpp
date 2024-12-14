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
    float getMedian(vector<int> &v)
    {
        if (v.size() % 2 == 0)
        {
            return (float)(v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2;
        }
        else
        {
            return (float)(v[v.size() / 2]);
        }
    }

    int getLowestClosest(vector<int> v, int left, int right, int value)
    {
        if (left + 1 == right || left >= right)
        {
            if (v[left] == value)
            {
                return left;
            }
            else if (v[right] == value)
            {
                return right;
            }
            else if (v[right] < value)
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
            if (value == v[mid])
            {
                return mid;
            }
            else if (value > v[mid])
            {
                cout << v[mid] << " smaller than " << value << endl;
                return getLowestClosest(v, mid, right, value);
            }
            else
            {
                cout << v[mid] << " larger than " << value << endl;
                return getLowestClosest(v, left, mid, value);
            }
        }
    }

    int getHighestClosest(vector<int> v, int left, int right, int value)
    {
        if (left + 1 == right || left >= right)
        {
            if (v[left] == value)
            {
                return left;
            }
            else if (v[right] == value)
            {
                return right;
            }
            else if (v[right] > value)
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
            if (value > v[mid])
            {
                return getHighestClosest(v, mid, right, value);
            }
            else
            {
                return getHighestClosest(v, left, mid, value);
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Get median of both
        double med1 = getMedian(nums1);
        double med2 = getMedian(nums2);

        cout << "The median is between " << med1 << " and " << med2 << endl;

        int left1, right1, left2, right2;

        if (med1 < med2)
        {
            left1 = getHighestClosest(nums1, 0, nums1.size() - 1, ceil(med1));
            right2 = getLowestClosest(nums2, 0, nums2.size() - 1, floor(med2));
            right1 = getLowestClosest(nums1, med1, nums1.size() - 1, floor(med2));
            left2 = getHighestClosest(nums2, 0, med2, ceil(med1));
        }
        else
        {
            left2 = getHighestClosest(nums2, 0, nums2.size() - 1, ceil(med2));
            right1 = getLowestClosest(nums1, 0, nums1.size() - 1, floor(med1));
            right2 = getLowestClosest(nums2, med2, nums2.size() - 1, floor(med1));
            left1 = getHighestClosest(nums1, 0, med1, ceil(med2));
        }
        cout << "left1: " << left1 << " right1: " << right1 << endl;
        cout << "left2: " << left2 << " right2: " << right2 << endl;

        // printing the numbers in range
        cout << "in nums1: ";
        for (int i = left1; i <= right1; i++)
        {
            cout << nums1[i] << " ";
        }
        cout << endl;

        cout << "in nums2: ";
        for (int i = left2; i <= right2; i++)
        {
            cout << nums2[i] << " ";
        }
        cout << endl;

        return 0.2;
    }
};
// @lc code=end

int main()
{
    Solution s;

    vector<int> nums1 = {1, 3, 4, 20};
    vector<int> nums2 = {1, 2, 4, 5, 6, 12};

    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

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

    cout << "Median should be: " << s.getMedian(nums1) << endl;
}