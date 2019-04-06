#include <cstdio>
#include <cstring>
#include <numeric>
#include <iostream>
#include <vector>
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
        itemRes.push_back(candidates[0]);
        res.push_back(itemRes);
        getEveryCombination(candidates, itemRes, 0, n, target, res);

        return res;
    }

    public:
    int getSum(vector<int> itemRes) {
        int n = itemRes.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += itemRes[i];
        }

        return res;
    }

    public:
    void getEveryCombination(vector<int>& candidates, vector<int> itemRes, int index, int len, int target, vector<vector<int> > res) {
        int sum = getSum(itemRes);
        if (index > len) {
            return;
        }
        if (sum == target) {
            res.push_back(itemRes);
            return;
        }

        if (sum + candidates[index] <= target) {
            itemRes.push_back(candidates[index]);
            getEveryCombination(candidates, itemRes, index, len, target, res);
            itemRes.pop_back();
        } else {
            itemRes.pop_back();
            getEveryCombination(candidates, itemRes, index + 1, len, target, res);
        }

        return;
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
