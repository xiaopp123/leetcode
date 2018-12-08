#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        string res = "";
        int index = len - 1;
        while (index >= 0) {
            if (s[index] != ' ') {
                break;
            }
            index--;
        }
        for (int i = index; i >= 0; i--) {
            if (s[i] == ' ') {
                break;
            }
            res += s[i];
        }
        return res.length();
    }
};

int main() {
    string s;
    while (cin >> s) {
        Solution* solution = new Solution();
        cout << solution->lengthOfLastWord(s) << endl;
    }
    return 0;
}
