#include <cstdio>
#include <limits.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (k == 1) {
            return min(nums1[0], nums2[0]);
        }
        if (i >= (int)nums1.size()) {
            return nums2[j + k - 1];
        }
        if (j >= (int)nums2.size()) {
            return nums1[i + k - 1];
        }
        int midv1 = -1;
        int midv2 = -1;
        if (i + k / 2 - 1 < (int)nums1.size()) {
            midv1 = nums1[i + k / 2 - 1];
        } else {
            midv1 = INT_MAX;
        }
        if (j + k / 2 - 1 < (int)nums2.size()) {
            midv2 = nums2[j + k / 2 - 1];
        } else {
            midv2 = INT_MAX;
        }

        if (midv1 < midv2) {
            return find(nums1, i + k / 2 - 1, nums2, j, k - k / 2);
        } else {
            return find(nums1, i, nums2, j + k / 2 - 1, k - k / 2);
        }

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int k1 = find(nums1, 0, nums2, 0, (m + n + 1) / 2);
        int k2 = find(nums1, 0, nums2, 0, (m + n + 2) / 2);
        return (k1 + k2) / 2;
    }
};

/* n + m
class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedNum;
        int i = 0, j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        while (i < len1 && j < len2) {
            if (nums1[i] < nums2[j]) {
                mergedNum.push_back(nums1[i++]);
            } else {
                mergedNum.push_back(nums2[j++]);
            }
        }
        while (i < len1) {
            mergedNum.push_back(nums1[i++]);
        }
        while (j < len2) {
            mergedNum.push_back(nums2[j++]);
        }
        int total = len1 + len2;
        if (total % 2) {
             return mergedNum[total / 2];
        } else {
            return (double)(mergedNum[total / 2]  + mergedNum[total / 2 - 1]) / 2;
        }
    }
};
*/

/*这个主要学习如何在两个有序数组里面 查找第 k 大的数,采用对k进行二分的方法
 * 首先从nums1中找第k/2大的数， 从nums2中找第k/2的数
 * 比较一下，谁小谁前面的数就不用考虑了，此时从小的那个往后递归，k变成了k - k / 2
 * 需要考虑一下边界条件，
 * 如果有一个数组到尽头了，只需从另一个数组里找第k个
 * 如果k==1,就比较两个数组的开头部分
 * 如果一个数组的k / 2越界，表示需要抛弃另一个数组前k / 2个，因为第k个肯定不再前k/2里面，所以为了配合上面的递归，越界返回一个最大值
 */
class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double k1 = (double)findKthNum(nums1, 0, nums2, 0, (n + m + 1) / 2);
        double k2 = (double)findKthNum(nums1, 0, nums2, 0, (n + m + 2) / 2);

        return (k1 + k2) / 2;

        //return ((double)findKthNum(nums1, 0, nums2, 0, (n + m + 1) / 2) + (double)findKthNum(nums1, 0, nums2, 0, (n + m + 2) / 2)) / 2;
    }

    public:
    int findKthNum(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= (int)nums1.size()) {
            return nums2[j + k - 1];
        }
        if (j >= (int)nums2.size()) {
            return nums1[i + k - 1];
        }
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        int midValLeft = i + k / 2 - 1 < (int) nums1.size() ? nums1[i + k / 2 - 1] : INT_MAX;
        int midValRight = j + k / 2 - 1 < (int) nums2.size() ? nums2[j + k / 2 - 1] : INT_MAX;

        if (midValLeft < midValRight) {
            return findKthNum(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKthNum(nums1, i, nums2, j + k / 2, k - k / 2);
        }

    }
};
int main() {
    Solution* solution = new Solution();
    vector<int> nums1, nums2;
    int n1, n2;
    while (cin >> n1 >> n2) {
        int t;
        for (int i = 0; i < n1; i++) {
            cin >> t;
            nums1.push_back(t);
        }
        for (int i = 0; i < n2; i++) {
            cin >> t;
            nums2.push_back(t);
        }
        cout << solution->findMedianSortedArrays(nums1, nums2) << endl;
    }
    return 0;
}
