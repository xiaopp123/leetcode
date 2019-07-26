#include "heads.h"
using namespace std;

class Solution {
    private:
        vector<int> _nums;
public:
    Solution(vector<int>& nums) {
        _nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = _nums;
        for (int i = 0; i < (int)res.size(); i++) {
        //    int t = (rand() % (i + 1));
            int t = i + rand() % (res.size() - i);
            swap(res[i], res[t]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main() {
    return 0;
}
