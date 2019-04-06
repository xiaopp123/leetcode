#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/*
 * 时间复杂的o(n),空间复杂的o（N）
class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int d[len];
        memset(d, 0, sizeof(d));
        for (int i = 0; i < len; i++) {
            d[nums[i]]++;
            if (d[nums[i]] > 1) {
                return nums[i];
            }
        }
    }
};
*/
/*
 * 二分查找index
 * 结果肯定是从1-n中出，所以二分查找
 * 以mid为标准，看看nums数组中 小于等于 mid的数cnt
 * 如果cnt <= mid, 说明重复的元素在右边
 * 否则在左边
 */

class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0; i < (int)nums.size(); i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
*/
class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int find = 0;
        while (find != slow) {
            find = nums[find];
            slow = nums[slow];
        }

        return find;
    }
};


int main() {
    int n;
    while (cin >> n) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();
        cout << solution->findDuplicate(nums) << endl;
    }
    return 0;
}

