#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        set<vector<int> > res;
        vector<int> item;
        set<int> vis;
        getPermute(nums, item, res, vis);
        set<vector<int> > :: iterator it;
        vector<vector<int> > returnRes;
        for (it = res.begin(); it != res.end(); it++) {
            returnRes.push_back(*it);
        }

        return returnRes;
    }

    public:
    void getPermute(vector<int>& nums, vector<int>& item, set<vector<int> >& res, set<int>& vis) {
        if ((int)item.size() == (int) nums.size()) {
            res.insert(item);
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
        vector<vector<int> > res = solution->permuteUnique(nums);
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
