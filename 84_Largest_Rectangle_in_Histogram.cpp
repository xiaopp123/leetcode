#include "heads.h"
using namespace std;

class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res = 0;
        heights.push_back(0);
        for (int i = 0; i < (int)heights.size(); i++) {
            if (st.empty() || heights[st.top()] < heights[i]) {
                st.push(i);
            } else {
                int cur = st.top();
                st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
                --i;
            }
        }
        return res;
    }
};

/*
class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < (int)heights.size(); i++) {
            if (i + 1 < (int)heights.size() && heights[i] < heights[i + 1]) {
                continue;
            }
            int minH = heights[i];
            for (int j = i; j >= 0; j--) {
                minH = min(minH, heights[i]);
                res = max(res, minH * (j - i + 1));
            }
        }
        return res;
    }
};
*/

int main() {
    Solution* solution = new Solution();
    vector<int> heights;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        heights.push_back(t);
    }
    cout << solution->largestRectangleArea(heights) << endl;
    delete solution;
    return 0;
}
