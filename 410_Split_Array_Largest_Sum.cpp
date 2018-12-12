#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
    int splitArray(vector<int>& nums, int m) {
        long long l = 0, r = 0;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] > l) {
                l = nums[i];
            }
            r += nums[i];
        }
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (can_split(nums, m, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
    private:
    int can_split(vector<int>& nums, int m, int mid) {
        int cnt = 1;
        long long sum = 0;
        int len = (int)nums.size();
        for (int i = 0; i < len; i++) {
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                sum = nums[i];
                cnt++;
                if (cnt > m) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int n;
    int m;
    while (cin >> n >> m) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();
        cout << solution->splitArray(nums, m) << endl;
    }
    return 0;
}
