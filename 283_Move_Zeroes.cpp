#include "heads.h"
using namespace std;

class Solution {
    public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return;
        }
        int noZeroAt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[noZeroAt++] = nums[i];
            }
        }
        for (int i = noZeroAt; i < n; i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    return 0;
}
