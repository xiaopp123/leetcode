#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> res;
        int len = s.length();
        int curRow = 0;
        bool changeDirect = false;

        for (int i = 0; i < numRows; i++) {
            res.push_back("");
        }

        for (int i = 0; i < len; i++) {
            res[curRow] += s[i];
            if (curRow == 0 || curRow == numRows - 1) {
                changeDirect = !changeDirect;
            }
            curRow += changeDirect ? 1 : -1;
        }
        string allres;
        for (int i = 0; i < numRows; i++) {
            allres += res[i];
        }

        return allres;
    }
};

int main() {
    int numRows;
    string s;
    while (cin >> s >> numRows) {
        Solution* solution = new Solution();
        cout << solution->convert(s, numRows) << endl;
    }
    return 0;
}
