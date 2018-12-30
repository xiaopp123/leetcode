#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
/**
 * https://leetcode.com/problems/product-of-array-except-self/
 * 开辟两个数组，一个记录前面的乘积，一个记录后面的乘积
 * 对于某个位置，结果就是前面的乘积 与 后面的乘积 相乘
 *
 * 还有一个优化空间的方法，
 * 只记录前面的乘积,并且放到结果数组res中
 * 然后从后往前遍历，用一个right来记录右边所有数的乘积
 */
/**
class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        if (len == 0) {
            return res;
        }
        vector<int> left(len);
        vector<int> right(len);
        left[0] = nums[0];
        right[len - 1] = nums[len - 1];
        for (int i = 1; i < len; i++) {
            left[i] = left[i - 1] * nums[i];
        }
        for (int i = len - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i];
        }
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                res.push_back(right[i + 1]);
            } else if (i == len - 1) {
                res.push_back(left[i - 1]);
            } else {
                res.push_back(left[i - 1] * right[i + 1]);
            }
        }
        return res;
    }
};
*/
class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        for (int i = 0; i < len - 1; i++) {
            res[i + 1] = res[i] * nums[i];
        }
        int right = 1;
        for (int i = len - 1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }

        return res;
    }
};


/**
class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long all = 1;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            all *= nums[i];
        }
        vector<int> res(len);
        for (int i = 0; i < len; i++) {
            res[i] = all / nums[i];
        }

        return res;
    }
};
*/
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
        vector<int> res = solution->productExceptSelf(nums);
        for (int i = 0; i < n; i++) {
            cout << res[i] << " " ;
        }
        cout << endl;
    }
    return 0;
}
