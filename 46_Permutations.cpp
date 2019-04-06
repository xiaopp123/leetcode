#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> item;
        set<int> vis;
        int n = nums.size();
        getPermute(nums, item, res, vis);

        return res;
    }

    public:
    void getPermute(vector<int>& nums, vector<int>& item, vector<vector<int> >& res, set<int>& vis) {
        if ((int)item.size() == (int) nums.size()) {
            res.push_back(item);
            return;
        }
        for (int i = 0; i < (int) nums.size(); i++) {
            if (vis.count(i)) {
                continue;
            }
            item.push_back(nums[i]);
            vis.insert(i);
            getPermute(nums, item, res, vis);
            vis.erase(i);
            item.pop_back();
        }
    }
};

int main() {
    int n;
    Solution* solution = new Solution();
    while (cin >> n) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        vector<vector<int> > res = solution->permute(nums);
        int m = res.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < (int)res[i].size(); j++) {
                cout << res[i][j] << " " << endl;
            }
            cout << endl;
        }

    }
    return 0;
}
