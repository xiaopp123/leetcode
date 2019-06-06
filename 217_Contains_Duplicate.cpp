#include "heads.h"
using namespace std;

class Solution {
    public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (mp.count(nums[i])) {
                return true;
            }
            mp[nums[i]]++;
        }
        return false;
    }
};

int main() {

    return 0;
}
