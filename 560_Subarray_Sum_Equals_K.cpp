#include "heads.h"
using namespace std;

/*
 * 利用前缀和的方式
 * sum[i] 表示[0, i]这个区间数的和，sum[j]表示[0, j]这个区间的和
 * 所以就是两重循环枚举i, j， 判断sum[j] - sum[i] == k
 *
 * 这个可以用hash表解决，一重循环优化
 * 枚举j, i = 当前和 - k
 */
class Solution {
    public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum;
        sum[0] = 1;
        int sub_sum = 0;
        int total = 0;
        for (auto num : nums) {
            sub_sum += num;
            total += sum[sub_sum - k];
            sum[sub_sum]++;
        }
        return total;
    }
};

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();
        cout << solution->subarraySum(nums, k) << endl;
    }
    return 0;
}
