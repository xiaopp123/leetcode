#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/**不仅要返回最后独立元素个数，还要保证数组的前几个数就是独立的数
 *https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = (int) nums.size();
        if (len == 0) {
            return 0;
        }
        int j = 0;
        for (int i = 1; i < len; i++) {
            if (nums[j] != nums[i]) {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }
};

int main() {
    int n;
    Solution* solution = new Solution();
    while (cin >> n) {
        vector<int> nums;
        int t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            nums.push_back(t);
        }
        cout << solution->removeDuplicates(nums);

    }

    return 0;
}
