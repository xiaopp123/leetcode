#include <cstdio>
#include <iostream>
#include <limits.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/**
 * https://leetcode.com/problems/perfect-squares/
 * 动态规划方式
 * dp[i] = min{dp[i - j * j]} + 1, j * j <= i
 *
/*
class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int j = 2; j <= n; j++) {
            int max_num = INT_MAX;
            for (int i = 1; i * i <= j; i++) {
                max_num = min(max_num, dp[j - i * i]);
            }
            dp[j] = max_num + 1;
        }

        return dp[n];
    }
};
*/
/**
 * 想用神搜的方式，好像不对
 */
class Solution {
    public:
        bool dfs(int n, int len, vector<int> squares, vector<int> & res) {
            if (n == 0) {
                return true;
            }
            if (len < 0) {
                return false;
            }
            for(int i = len; i >=0; i--) {
                if (n - squares[i] >= 0) {
                    res.push_back(squares[i]);
                    if (dfs(n - squares[i], i, squares, res)) {
                        return true;
                    }
                    res.pop_back();
                }
                if (dfs(n, i - 1, squares, res)) {
                    return true;
                }
            }
            return false;
        }
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }
        vector<int> res;
        dfs(n, squares.size() - 1, squares, res);

        return res.size();
    }
};

int main() {
    int n;
    while (cin >> n) {
        Solution* solution = new Solution();
        cout << solution->numSquares(n) << endl;
    }
    return 0;
}
