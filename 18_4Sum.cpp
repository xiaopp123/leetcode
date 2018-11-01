#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/**
 * https://leetcode.com/problems/4sum/description/
 * 解法同15题，三个数求和，这里多一层循环
 */

class Solution {
    public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int> > res;
        set<vector<int> > reSet;
        int s, e;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                s = j + 1;
                e = n - 1;
                while (s < e) {
                    int sum = nums[i] + nums[j] + nums[s] + nums[e];
                    if (sum == target)  {
                        vector<int> record;
                        record.push_back(nums[i]);
                        record.push_back(nums[j]);
                        record.push_back(nums[s]);
                        record.push_back(nums[e]);
                        reSet.insert(record);
                        s++;
                    } else if (sum < target) {
                        s++;
                    } else {
                        e--;
                    }
                }
            }
        }
        set< vector<int> > :: iterator it;
        for (it = reSet.begin(); it != reSet.end(); it++) {
            res.push_back(*it);
        }

        return res;
    }
};

int main() {
    Solution* solution = new Solution();
    int n;
    int target;
    while (cin >> n) {
        int t;
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            cin >> t;
            nums.push_back(t);
        }
        cin >> target;

        vector<vector<int> > res = solution->fourSum(nums, target);
        for (int i = 0; i < (int)res.size(); i++) {
            for (int j = 0; j < (int) res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
