#include "heads.h"
using namespace std;

class Solution {
    public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1;
        int end = -2;
        int n = (int)nums.size();
        int mx = nums[0];
        int mn = nums[n - 1];
        for (int i = 1; i < (int)nums.size(); i++) {
            mx = max(mx, nums[i]);
            if (mx > nums[i]) {
                end = i;
            }
            mn = min(mn, nums[n - i - 1]);
            if (mn < nums[n - i - 1]) {
                start = n - i - 1;
            }
        }
        return end - start + 1;
    }
};
/*
class Solution {
    public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int start = -1;
        int end = -2;
        for (int i = 0; i < (int)tmp.size(); i++) {
            if (tmp[i] != nums[i]) {
                start = i;
                break;
            }
        }
        for (int i = (int)tmp.size() - 1; i >= 0; i--) {
            if (tmp[i] != nums[i]) {
                end = i;
                break;
            }
        }
        return end - start + 1;
    }
};
*/
/*
class Solution {
    public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1;
        int res = 0;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                int j = i;
                while (j > 0 && nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                    j--;
                }
                if (start == -1 || start > j) {
                    start = j;
                }
                res = i - start + 1;
            }
        }
        return res;
    }
};
*/

int main() {
    return 0;
}
