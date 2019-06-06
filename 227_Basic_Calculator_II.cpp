#include "heads.h"
using namespace std;

class Solution {
    public:
    int calculate(string s) {
        vector<char> opts = {'+', '-', '*', '/'};

        stack<string> st;
        string str;
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (find(opts.begin(), opts.end(), s[i]) != opts.end()) {
                st.push(str);
                str = "";
            } else {
                str += s[i];
            }
        }
        int res = 0;
        return res;
    }
};

int main() {
    return 0;
}
