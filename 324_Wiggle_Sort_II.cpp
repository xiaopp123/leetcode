#include "heads.h"
using namespace std;

class Solution {
    public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res;
        int pre = 0;
        int aft = n - 1;
        if (n % 2 == 0) {
            pre = n / 2 - 1;
        } else {
            pre = n / 2;
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                res.push_back(nums[pre--]);
            } else {
                res.push_back(nums[aft--]);
            }
        }
        nums = res;
    }
};

int main() {

    return 0;
}
