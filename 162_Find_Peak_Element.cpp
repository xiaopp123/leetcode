#include "heads.h"
using namespace std;

class Solution {
    public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        for (int i = 1; i <= n; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i - 1;
            }
        }
    }
};

int main() {
    return 0;
}
