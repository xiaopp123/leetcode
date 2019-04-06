#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            nums[(nums[i] - 1) % len] += len;
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] > 2 * len) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
/*
class Solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] - 1 != i) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
*/
/*
class Solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                res.push_back(idx + 1);
            } else {
                nums[idx] = -nums[idx];
            }
        }
        return res;
    }
};
*/

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    Solution* solution = new Solution();
    vector<int> res = solution->findDuplicates(nums);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
