#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * 这里的重复指的是出现次数小于等于2
 * 设置一个计数器cnt，表示允许重复的次数,初始化为1,表示允许重复一次，
 * 如果pre和cur相等时，判断cnt是否等于0,如果等于0表示已经重复出现两次了，所以cur++
 *                                      如果不等于0表示可以重复一次,cnt--
 *
 * 如果不相等，cnt = 1
 * 返回的是pre + 1
 */

class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 2) {
            return n;
        }
        int pre = 0, cur = 1, cnt = 1;
        while (cur < n) {
            if (nums[cur] == nums[pre] && cnt == 0) {
                cur++;
                continue;
            }
            if (nums[cur] == nums[pre]) {
                cnt--;
            } else {
                cnt = 1;
            }
            nums[++pre] = nums[cur++];
        }
        return pre + 1;
    }
};

int main() {
    Solution *solution = new Solution();
    int n;
    while (cin >> n) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        cout << solution->removeDuplicates(nums);
    }
    return 0;
}
