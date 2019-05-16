#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        int n = T.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && T[i] >= T[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top() - i;
            } else {
                res[i] = 0;
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
