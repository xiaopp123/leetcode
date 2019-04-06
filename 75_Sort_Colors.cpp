#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 1、计数排序，需要两次扫描
 * 2、类似于二分的思想,设置左右两个指针,left 的左边全是0，所以left是第一个不是0的，right右边全是2，所以right是从右往左第一个不是2的数
 *
 */

/*
class Solution {
    public:
    void sortColors(vector<int>& nums) {
        int cnt[3];
        memset(cnt, 0, sizeof(cnt));
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            cnt[nums[i]]++;
        }
        int index = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                nums[index++] = i;
            }
        }

        for (int i = 0; i < len; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};
*/

class Solution {
    public:
    void sortColors(vector<int>& nums) {
        int len = (int)nums.size();
        int left = 0;
        int right = len - 1;
        int i = 0;
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[left], nums[i]);
                left++;
                i++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[right], nums[i]);
                right--;
            }
        }
        for (int i = 0; i < len; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution* solution = new Solution();
    int n;
    while (cin >> n) {
        int t;
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            cin >> t;
            nums.push_back(t);
        }
        solution->sortColors(nums);
    }

    return 0;
}
