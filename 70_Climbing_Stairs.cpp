#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;


class Solution {
    public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};

int main() {
    return 0;
}
