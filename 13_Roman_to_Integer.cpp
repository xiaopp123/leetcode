#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int romanToInt(string s) {
        /**
            I             1
            V             5
            X             10
            L             50
            C             100
            D             500
            M             1000
        */
        map<char, int> g;
        g['I'] = 1;
        g['V'] = 5;
        g['X'] = 10;
        g['L'] = 50;
        g['C'] = 100;
        g['D'] = 500;
        g['M'] = 1000;


        int len = s.length();
        int index = 0;
        int res = 0;
        while (index < len) {
            if (s[index] == 'I') {
                if (index + 1 < len && s[index + 1] == 'V') {
                    res = res + 4;
                    index += 2;
                    continue;
                } else if (index + 1 < len && s[index + 1] == 'X') {
                    res = res + 9;
                    index += 2;
                    continue;
                }
            } else if (s[index] == 'X') {
                if (index + 1 < len && s[index + 1] == 'L') {
                    res = res + 40;
                    index += 2;
                    continue;
                } else if (index + 1 < len && s[index + 1] == 'C') {
                    res = res + 90;
                    index += 2;
                    continue;
                }
            } else if (s[index] == 'C') {
                if (index + 1 < len && s[index + 1] == 'D') {
                    res = res + 400;
                    index += 2;
                    continue;
                } else if (index + 1 < len && s[index + 1] == 'M') {
                    res = res + 900;
                    index += 2;
                    continue;
                }
            }
            res = res + g[s[index]];
            index++;
        }

        return res;
    }
};

int main() {
    string s;
    Solution *solution = new Solution();
    while (cin >> s) {
        cout << solution->romanToInt(s) << endl;
    }
    return 0;
}
