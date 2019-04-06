#include "heads.h"
using namespace std;

class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            res ^= nums[i];
        }
        return res;
    }
};

int main() {
    return 0;
}
