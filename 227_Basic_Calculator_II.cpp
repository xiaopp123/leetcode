#include "heads.h"
using namespace std;

class Solution {
    public:
    int calculate(string s) {
        char opt = '+';
        int res = 0;
        int cur_res = 0;
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' && i != n - 1) {
                continue;
            }
            if (s[i] >= 0 && s[i] <= 9) {
                num = num * 10 + (s[i] - '0');
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == n - 1) {
                switch(opt) {
                    case '+' : cur_res += num; break;
                    case '-' : cur_res -= num; break;
                    case '*' : cur_res *= num; break;
                    case '/' : cur_res /= num; break;
                }
                if (s[i] == '+' || s[i] == '-' || i == n - 1) {
                    res += cur_res;
                    cur_res = 0;
                }
                opt = s[i];
                num = 0;
            }
        }
        return res;
    }
};

class Solution {
    public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        int sign = 1;
        char opt = '+';
        int n = (int)s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' && i != n - 1) {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }
            if (s[i] < '0' || i == n - 1) {
                if (opt == '+' || opt == '-') {
                    sign = (opt == '+' ? 1 : -1);
                    num *= sign;
                } else if (opt == '*' || opt == '/') {
                    num = (opt == '*' ? num * st.top() : st.top() / num);
                    st.pop();
                }
                st.push(num);
                opt = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    string s;
    cin >> s;
    cout << solution->calculate(s) << endl;

    return 0;
}
