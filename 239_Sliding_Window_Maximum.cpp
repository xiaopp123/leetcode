#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> que;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (!que.empty() && que.front() == i - k) {
                que.pop_front();
            }
            while (!que.empty() && nums[que.back()] < nums[i]) {
                que.pop_back();
            }
            que.push_back(i);
            if (i >= k - 1 && !que.empty()) {
                res.push_back(nums[que.front()]);
            }
        }

        return res;
    }
};

int main() {
    return 0;
}
