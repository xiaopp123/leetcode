#include "heads.h"
using namespace std;

class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        set<int> mp;
        for (auto num : nums) {
            mp.insert(num);
        }

        int strike = 0;
        for (auto num : mp) {
            if (mp.count(num - 1) > 0) {
                continue;
            }
            int cur_num = num;
            int cur_strike = 1;
            while (mp.count(cur_num + 1) > 0) {
                cur_strike++;
                cur_num++;
            }
            strike = max(strike, cur_strike);
        }

        return strike;
    }
};
/*
class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int strike = 0;
        int index = 0;
        int cur_strike = 1;
        while (index < (int)nums.size()) {
            strike = max(cur_strike, strike);
            if (index + 1 < (int)nums.size()) {
                if (nums[index] == nums[index + 1]) {
                    index++;
                    continue;
                }
                if (nums[index] + 1 == nums[index + 1]) {
                    cur_strike++;
                    index++;
                    continue;
                }
                cur_strike = 1;
            }
            index++;
        }

        return strike;
    }
};
*/

/*
class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        int strike = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int cur_num = nums[i];
            int cur_strike = 1;
            while (array_contain(nums, cur_num + 1)) {
                cur_strike++;
                cur_num++;
            }
            strike = max(cur_strike, strike);
        }

        return strike;
    }

    bool array_contain(const vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == target) {
                return true;
            }
        }
        return false;
    }
};
*/

int main() {

    return 0;
}
