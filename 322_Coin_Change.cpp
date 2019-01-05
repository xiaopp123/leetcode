#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/**
 * 背包题
 * 01背包只取一个，这个背包可以取多个，
 * 01背包，第一层循环是个数，第二层是容量
 * 这个背包因为可以取多个，所以第一层是容量，第二层是个数
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if (n == 0) {
            return 0;
        }
        vector<int> res(amount + 1, INT_MAX);
        res[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i - coins[j] >= 0 && res[i - coins[j]] != INT_MAX) {
                    res[i] = min(res[i], res[i - coins[j]] + 1);
                }
            }
        }

        return res[amount] == INT_MAX ? -1 : res[amount];
    }
};

int main() {
    int n, amount;
    while (cin >> n >> amount) {
        vector<int> coins;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            coins.push_back(t);
        }
        Solution *solution = new Solution();
        cout << solution->coinChange(coins, amount) << endl;
    }
    return 0;
}
