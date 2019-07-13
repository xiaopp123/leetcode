#include "heads.h"
using namespace std;

class Solution {
    public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < (int)nums.size(); i++) {
            res ^= (i ^ nums[i]);
        }
        return res;
    }
};
/*
class Solution {
    public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(n + 1, 0);
        for (auto num : nums) {
            mp[num]++;
        }
        for (int i = 0; i < n + 1; i++) {
            if (mp[i] == 0) {
                return i;
            }
        }
        return 0;
    }
};
*/

int main() {
    return 0;
}
