#include "heads.h"
using namespace std;
class Solution {
    public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int min_len = INT_MAX;
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
            //    if (sum == s) {
                    min_len = min(min_len, i - left + 1);
            //   }
                sum -= nums[left];
                left++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
/*
class Solution {
    public:
    int search(int left, int right, int target, int arr[]) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target <= arr[mid]) {
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            }
        }
        return right;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int sum[len + 1];
        int res = len + 1;
        sum[0] = 0;
        for (int i = 1; i < len + 1; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < len; i++) {
            int right = search(i + 1, len, sum[i] + s, sum);
            if (right == len + 1) {
                break;
            }
            res = min(res, right - i);
        }
        return res == len + 1 ? 0 : res;
    }
};
*/

/*
class Solution {
    public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int res = INT_MAX;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                res = min(res, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

class Solution {
    public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int first = -1;
        int second = -1;
        int res = INT_MAX;
        int sum = 0;
        while (++second < (int)nums.size()) {
            sum += nums[second];
            if (sum < s) {
                continue;
            }
            res = min(res, second - first);
            while (++first < second) {
                sum -= nums[first];
                if (sum < s) {
                    break;
                }
                res = min(res, second - first);
            }
        }
        return res == INT_MAX ? 0 : res;
    }

};
*/

int main() {
    return 0;
}
