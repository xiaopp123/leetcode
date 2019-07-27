#include "heads.h"
using namespace std;

class Solution {
public:
    map<int, vector<int>> g;
    vector<int> nums;
    Solution(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            g[nums[i]].push_back(i);
        }
        this->nums = nums;
    }
    int pick(int target) {
        //vector<int> ids;
        int cnt = 0;
        int res = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == target) {
                cnt++;
                if (rand() % cnt == 0) {
                    res = i;
                }
            }

        }
        return res;
    }

    /*
    int pick(int target) {
        vector<int> vec = g[target];
        int res = vec[0];
        int i = 2;
        while(i < (int)vec.size()) {
            int t = rand() % i;
            if (t == 0) {
                res = vec[i];
            }
        }

        return res;
    }
    */
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main() {
    return 0;
}
