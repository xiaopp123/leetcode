#include "heads.h"
using namespace std;
class Solution {
    public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k % nums.size() == 0) {
            return ;
        }
        int idx = 0;
        int pre = nums[0];
        int cur = nums[0];
        int n = nums.size();
        int start = 0;
        for (int i = 0; i < n; i++) {
            pre = cur;
            idx = (idx + k) % n;
            cur = nums[idx];
            nums[idx] = pre;
            if (idx == start) {
                idx = ++start;
                cur = nums[idx];
            }
        }
    }
};


class Solution {
    public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        while (k--) {
            nums.insert(nums.begin(), nums[n - 1]);
            nums.pop_back();
        }
    }
};

int main() {
    return 0;
}
