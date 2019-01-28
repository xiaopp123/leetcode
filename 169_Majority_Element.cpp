#include "heads.h"

using namespace std;

/*
 * 时间n, 空间1
 * 先将第一个出现的作为目标值，如果下一个出现的是目标值，计数+1，否则计数-1，如果计数为0，将当前作为目标值
 * 为什么成立？
 * 因为目标值的的个数会大于总数的一半，所以最后一定是目标值
 *
 */
class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        int target;
        int cnt = 0;
        for (auto &num : nums) {
            if (cnt == 0) {
                target = num;
                cnt++;
            } else {
                if (target == num) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
        return target;
    }
};
//h哈希，时间n，空间n
/*
class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        map<int, int> cnt;
        int n = nums.size();
        //cout << n / 2;
        for (auto &num : nums) {
            if(cnt[num] >= n / 2) {
                return num;
            } else {
                cnt[num]++;
         //       cout << "num: " << num << " cnt: " << cnt[num] << endl;
            }
        }
        return 0;
    }
};
*/

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();
        cout << solution->majorityElement(nums) << endl;

    }
    return 0;
}
