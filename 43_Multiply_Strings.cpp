#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

class Solution {
    public:
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        string res;
        int lv = l1 + l2;
        vector<int> resV(lv, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                resV[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carry = 0;
        for (int i = 0; i < lv; i++) {
            int resT = (resV[i] + carry) % 10;
            carry = (resV[i] + carry) / 10;
            resV[i] = resT;
        }

        int end = lv - 1;
        while (end >= 0) {
            if(resV[end] != 0) {
                break;
            }
            end--;
        }
        if (end < 0) {
            res.push_back('0');
        } else {
            for (int i = end; i >= 0; i--) {
                res.push_back(resV[i] + '0');
            }
        }

        return res;

    }
};

int main() {
    string num1, num2;
    Solution* solution = new Solution();
    while (cin >> num1 >> num2) {
        cout << solution->multiply(num1, num2) << endl;
    }
    return 0;
}

