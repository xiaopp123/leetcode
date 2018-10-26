#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/integer-to-roman/description/
 * 打表题
 */

class Solution {
    public:
    string intToRoman(int num) {
        struct Map {
            string x;
            int y;
        };
        Map m[13];
        m[0].x = "I";
        m[0].y = 1;
        m[1].x = "IV";
        m[1].y = 4;
        m[2].x = "V";
        m[2].y = 5;
        m[3].x = "IX";
        m[3].y = 9;
        m[4].x = 'X';
        m[4].y = 10;
        m[5].x = "XL";
        m[5].y = 40;
        m[6].x = "L";
        m[6].y = 50;
        m[7].x = "XC";
        m[7].y = 90;
        m[8].x = "C";
        m[8].y = 100;
        m[9].x = "CD";
        m[9].y = 400;
        m[10].x = "D";
        m[10].y = 500;
        m[11].x = "CM";
        m[11].y = 900;
        m[12].x = "M";
        m[12].y = 1000;

        string res;
        while (num) {
            for (int i = 12; i >=0; i--) {
                if (num >= m[i].y) {
                    res += m[i].x;
                    num -= m[i].y;
                    break;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution* solution = new Solution();
    int num;
    while (cin >> num) {
        cout << solution->intToRoman(num) << endl;
    }
    return 0;
}
