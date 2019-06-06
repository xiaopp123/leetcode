#include "heads.h"
using namespace std;

class Solution {
    public:
    int calculate(string s) {
        int res = 0;
        stack<int> st;
        int sign = 1;
        int num = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-') {
                res += num * sign;
                num = 0;
                sign = (s[i] == '+' ? 1 : -1);
            } else if (s[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res += num * sign;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
                num = 0;
            }
        }
        return res + num * sign;
    }
};

int main() {

    return 0;
}
