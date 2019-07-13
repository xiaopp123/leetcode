#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        vector<int> cooldown(n, 0);
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);

        buy[0] = -prices[0];
        cooldown[0] = 0;
        sell[0] = INT_MIN;

        int profit = INT_MIN;
        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], cooldown[i - 1] - prices[i]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
            cooldown[i] = max(sell[i - 1], max(buy[i - 1], cooldown[i - 1]));
            profit = max(cooldown[i], max(buy[i], sell[i]));
        }

        return profit;
    }
};

int main() {
    return 0;
}
