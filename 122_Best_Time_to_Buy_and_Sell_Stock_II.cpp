#include "heads.h"
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        int i = 0;
        int res = 0;
        if (n <= 1) {
            return res;
        }
        int minn = prices[0];
        int maxx = prices[0];
        while (i + 1 < n) {
            while (i + 1 < n && prices[i + 1] <= prices[i]) {
                i++;
            }
            minn = prices[i];
            while (i + 1 < n && prices[i + 1] >= prices[i]) {
                i++;
            }
            maxx = prices[i];
            res += (maxx - minn);
        }

        return res;
    }
};

int main() {
    Solution* solution = new Solution();
    vector<int> prices;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        prices.push_back(t);
    }
    cout << solution->maxProfit(prices) << endl;
    return 0;
}
