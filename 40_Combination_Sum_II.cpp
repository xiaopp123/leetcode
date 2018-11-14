#include <cstdio>
#include <set>
#include <cstring>
#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        set<vector<int> > reSet;
        int n = candidates.size();
        if (n == 0) {
            return res;
        }
        vector<int> itemRes;
        sort(candidates.begin(), candidates.end());
        getEveryCombination(reSet, candidates, itemRes, 0, target, 0);

        set<vector<int> > :: iterator it;
        for (it = reSet.begin(); it != reSet.end(); it++) {
            res.push_back(*it);
        }
        return res;
    }

    public:
    void getEveryCombination(set<vector<int> >& res, vector<int>& candidates, vector<int> itemRes, int sum, int target, int cur) {
        if (sum == target) {
            res.insert(itemRes);
            return;
        }
        for (int i = cur; i < (int)candidates.size(); i++) {
            sum += candidates[i];
            if (sum > target) {
                return;
            }
            itemRes.push_back(candidates[i]);
            getEveryCombination(res, candidates, itemRes, sum, target, i + 1);
            sum -= candidates[i];
            itemRes.pop_back();
        }
    }
};
int main() {
    Solution* solution = new Solution();
    int n, target;
    while (cin >> n >> target) {
        vector<int> candidates;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            candidates.push_back(t);
        }
        vector<vector<int> > res = solution->combinationSum2(candidates, target);
        int len = res.size();
        for (int i = 0; i < len; i++) {
            int itemLen = res[i].size();
            for (int j = 0; j < itemLen; j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
