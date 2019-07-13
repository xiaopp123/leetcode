#include "heads.h"
using namespace std;
class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int min_prices = prices[0];
        int res = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            res = max(res, prices[i] - min_prices);
            if (prices[i] < min_prices) {
                min_prices = prices[i];
            }
        }

        return res;
    }
};

//class Solution {
//    public:
//    int maxProfit(vector<int>& prices) {
//        /*
//        vector<int> pre_min = prices;
//        vector<int> aft_max = prices;
//        int n = prices.size();
//        for (int i = 0; i < n; i++) {
//            if (i > 0) {
//                pre_min[i] = min(pre_min[i - 1], pre_min[i]);
//            }
//        }
//        for (int i = n - 1; i > 0; i--) {
//            if (i < n - 1 ) {
//                aft_max[i] = max(aft_max[i + 1], aft_max[i]);
//            }
//        }
//        int res = 0;
//        for (int i = 0; i < n; i++) {
//            res = max(res, aft_max[i] - pre_min[i]);
//        }
//        return res;
//        */
//        int min_price = INT_MAX;
//        int res = 0;
//        for (int i = 0; i < (int)prices.size(); i++) {
//            if (prices[i] < min_price) {
//                min_price = prices[i];
//            } else {
//                res = max(res, prices[i] - min_price);
//            }
//        }
//        return res;
//    }
//};

int main() {
    return 0;
}
