#include "heads.h"
using namespace std;

class Solution {
    public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        if (n == 1) {
            return stoi(tokens[0]);
        }
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || \
                    tokens[i] == "*" || tokens[i] == "/") {
                if (!st.empty()) {
                    int second_num = st.top();
                    st.pop();
                    int first_num = st.top();
                    st.pop();
                    int res = 0;
                    if (tokens[i] == "+") {
                        res = first_num + second_num;
                    } else if (tokens[i] == "-") {
                        res = first_num - second_num;
                    } else if (tokens[i] == "*") {
                        res = first_num * second_num;
                    } else if (tokens[i] == "/") {
                        res = first_num / second_num;
                    }
                    st.push(res);
                }
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

int main() {
    return 0;
}
