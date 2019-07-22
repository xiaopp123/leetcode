#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) {
            return {};
        }
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && T[i] >= T[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = 0;
            } else {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> T = {73,74,75,71,69,72,76,73};
    Solution* solution = new Solution();
    solution->dailyTemperatures(T);
    return 0;
}
