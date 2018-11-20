#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

string Longest_Common_Subsequence(string st1, string st2) {
    int l1 = st1.length();
    int l2 = st2.length();
    string res;
    if (l1 == 0 || l2 == 0) {
        return res;
    }
    int dp[l1 + 1][l2 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            if (st1[i] == st2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[l1][l2] << endl;

    while (l1 > 0 && l2 > 0) {
        if (st1[l1 - 1] == st2[l2 - 1]) {
            l1--;
            l2--;
            res += st1[l1];
        } else {
            if (dp[l1][l2 - 1] > dp[l1 - 1][l2]) {
                l2--;
            } else {
                l1--;
            }
        }
    }
    reverse(res.begin(), res.end());


    return res;
}


int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << Longest_Common_Subsequence(str1, str2) << endl;
    }

    return 0;
}
