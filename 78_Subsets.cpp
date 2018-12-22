#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    public:
        vector<vector<int> > res;
    public:
        void dfs(int s, int e, vector<int> item, set<int> vis, vector<int> nums) {
            if (s == e) {
                return;
            }
            for (int i = s; i < e; i++) {
                if (vis.count(nums[i]) == 0) {
                    vis.insert(nums[i]);
                    item.push_back(nums[i]);
                    res.push_back(item);
                    dfs(i + 1, e, item, vis, nums);
                    vis.erase(nums[i]);
                    item.pop_back();
                }
            }
        }
    public:
    vector<vector<int> > subsets(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> item;
        set<int> vis;
        res.push_back(item);
        dfs(0, n, item, vis, nums);

        return res;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();
        vector<vector<int> > res = solution->subsets(nums);
        int len = res.size();
        cout << len << endl;
        for (int i = 0; i < len; i++) {
            int item_len = res[i].size();
            for (int j = 0; j < item_len; j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
