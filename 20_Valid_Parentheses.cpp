#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * too easy
 */
class Solution {
    public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                // attention
                if (st.size() == 0) {
                    return false;
                }
                char topStack = st.top();
                st.pop();
                if ((s[i] == ')' && topStack == '(') || (s[i] == ']' && topStack == '[') || (s[i] == '}' && topStack == '{') ) {
                    continue;
                }
                return false;
            }
        }
        if (st.size() == 0) {
            return true;
        }
        return false;
    }
};
int main() {
    Solution *solution = new Solution();
    string s;
    while (cin >> s) {
        cout << solution->isValid(s) << endl;
    }

    return 0;
}
