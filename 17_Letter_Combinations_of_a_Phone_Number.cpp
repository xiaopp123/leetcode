#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 * 递归
 * 首先将所有数字与字母映射表进行打表记录
 * 然后进行递归操作
 * 递归结束条件是拼成的字符串长度等于输入字符串长度
 */

class Solution {
    public:
        vector<string> mg;
        vector<string> total_res;
    public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return total_res;
        }
        int n = digits.length();
        mg.push_back("");
        mg.push_back("");
        mg.push_back("abc");
        mg.push_back("def");
        mg.push_back("ghi");
        mg.push_back("jkl");
        mg.push_back("mno");
        mg.push_back("pqrs");
        mg.push_back("tuv");
        mg.push_back("wxyz");

        get_letter_combination(digits, 0, n, "");

        return total_res;
    }
    private:
    void get_letter_combination(string digits, int index, int len, string res) {
        if (index == len) {
            if ((int)res.length() == len) {
                total_res.push_back(res);
            }

            return;
        }

        for (int i = index; i < len; i++) {
            string mp = mg[digits[i] - '0'];
            int mpLen = mp.size();
            for (int j = 0; j < mpLen; j++) {
                get_letter_combination(digits, i + 1, len, res + mp[j]);
            }
        }
    }
};

int main() {
    Solution* solution = new Solution();
    string digits;
    while (cin >> digits) {
        vector<string> res = solution->letterCombinations(digits);
        for (int i = 0; i < (int) res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;

    }

    return 0;
}
