#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

/*使用动态规划记录左边的最高长度和右边的最高长度
 *
class Solution {
    public:
    int trap(vector<int>& height) {
        int len = height.size();
        int ans  = 0;
        if (len == 0) {
            return ans;
        }
        vector<int> left(len), right(len);
        left[0] = height[0];
        for (int i = 1; i < len; i++) {
            left[i] = max(left[i - 1], height[i]);
        }
        right[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        for (int i = 1; i < len - 1; i++) {
            ans += min(left[i], right[i]) - height[i];
        }

        return ans;
    }
};
*/
class Solution {
    public:
    int trap(vector<int>& height) {
        int len = height.size();
        int ans = 0;
        if (len == 0) {
            return ans;
        }
        stack<int> st;
        for (int i = 0; i < len; i++) {
            int cur = height[i];
            while (!st.empty() && cur > height[st.top()]) {
                int top = st.top();
                st.pop();
                if(st.empty()) {
                    break;
                }
                int distance = i - st.top() - 1;
                int h = min(height[st.top()], cur) - height[top];
                ans += distance * h;
            }
            st.push(i);

        }

        return ans;
    }
};



int main() {
    Solution* solution = new Solution();
    vector<int> height;
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            height.push_back(temp);
        }
        cout << solution->trap(height) << endl;
    }

    return 0;
}
