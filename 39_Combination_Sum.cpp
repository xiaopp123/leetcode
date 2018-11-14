#include <cstdio>
#include <cstring>
#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        int n = candidates.size();
        if (n == 0) {
            return res;
        }
        vector<int> itemRes;
        sort(candidates.begin(), candidates.end());
        getEveryCombination(res, candidates, itemRes, 0, target, 0);

        return res;
    }

    public:
    void getEveryCombination(vector<vector<int> >& res, vector<int>& candidates, vector<int> itemRes, int sum, int target, int cur) {
        if (sum == target) {
            res.push_back(itemRes);
            return;
        }
        for (int i = cur; i < (int)candidates.size(); i++) {
            sum += candidates[i];
            if (sum > target) {
                return;
            }
            itemRes.push_back(candidates[i]);
            getEveryCombination(res, candidates, itemRes, sum, target, i);
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
        vector<vector<int> > res = solution->combinationSum(candidates, target);
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
