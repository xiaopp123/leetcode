#include "heads.h"
using namespace std;


class Solution {
    public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> order_nums;
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            /*int left = 0;
            int right = order_nums.size();
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[i] > order_nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            res[i] = right;
            order_nums.insert(order_nums.begin() + right, nums[i]);
            */
            int index = lower_bound(order_nums.begin(), order_nums.end(), nums[i]) - order_nums.begin();
            res[i] = index;
            order_nums.insert(order_nums.begin() + index, nums[i]);
        }

        return res;
    }
};
/*
class Solution {
    public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            int counter = 0;
            for (int j = i + 1; j < (int)nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    counter++;
                }
            }
            res.push_back(counter);
        }
        return res;
    }
};
*/

int main() {
    return 0;
}



