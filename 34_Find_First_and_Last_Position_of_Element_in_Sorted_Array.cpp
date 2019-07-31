#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> res;
            if (nums.empty()) {
                res.push_back(-1);
                res.push_back(-1);
                return res;
            }
            int left = find_left(nums, target);
            int right = find_right(nums, target);
            res.push_back(left);
            res.push_back(right);

            return res;

        }
        int find_left(vector<int>& nums, int target) {
            int l = 0;
            int r = nums.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid] >= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (r + 1 < (int)nums.size() && nums[r + 1] == target) {
                return r + 1;
            } else {
                return -1;
            }
        }
        int find_right(vector<int>& nums, int target) {
            int l = 0;
            int r = nums.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid] <= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (l - 1 >= 0 && nums[l - 1] == target) {
                return l - 1;
            } else {
                return -1;
            }
        }
};
/**
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 */

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int len = (int) nums.size();
            vector<int> res;
            res.push_back(-1);
            res.push_back(-1);
            if (len == 0) {
                return res;
            }
            int left = searchIndex(nums, target, true);

            if (left == len || target != nums[left]) {
                left = -1;
            }
            int right = searchIndex(nums, target, false) - 1;

            if (right != -1 && nums[right] != target) {
                right = -1;
            }

            res[0] = left;
            res[1] = right;

            return res;
        }
    public:
        int searchIndex(vector<int>& nums, int target, bool left) {
            int l = 0;
            int r = nums.size();
            while (l < r) {
                int mid = (l + r) / 2;
                if (nums[mid] > target || (left && nums[mid] == target)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }

            }
            return l;
        }
};

/*
class Solution {
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            vector<int> res;
            res.push_back(-1);
            res.push_back(-1);

            return res;
        }
        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        vector<int> res;
        res.push_back(left);
        res.push_back(right);

        return res;
    }
    public:
    int findLeft(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (r == (int)nums.size() || nums[r] != target) {
            return -1;
        } else {
            return r;
        }
    }

    public:
    int findRight(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (nums[l - 1] == target) {
            return l - 1;
        } else {
            return -1;
        }
    }
};
*/
int main() {
    int n, m;
    Solution* solution = new Solution();
    while (cin >> n >> m) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        vector<int> res = solution->searchRange(nums, m);
        cout << res[0] << " " << res[1] << endl;

    }
    return 0;
}
