#include "heads.h"
using namespace std;

class Solution {
    public:
    int get_area(vector<int> g) {
        int max_area = 0;
        stack<int> s;
        int n = g.size();
        for (int i = 0; i < n; i++) {
            if (s.empty() || g[s.top()] < g[i]) {
                s.push(i);
            } else {
                int cur = s.top();
                s.pop();
                int cur_area = g[cur] * (s.empty() ? i : i - s.top() - 1);
                max_area = max(max_area, cur_area);
                i--;
            }
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return 0;
        }
        vector<vector<int>> g(n, vector<int>((m + 1), 0));
        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == '1') {
                g[0][i] = 1;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                g[j][i] += (matrix[j][i] == '1' ? g[j - 1][i] + 1 : 0);
            }
        }
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            max_area = max(max_area, get_area(g[i]));
        }
        return max_area;
    }
};

int main() {
    vector<vector<char>> matrix;
    Solution* solution = new Solution();
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        vector<char> ch;
        ch.clear();
        for (int j = 0; j < (int)s.length(); j++) {
            ch.push_back(s[j]);
        }
        matrix.push_back(ch);
    }
    cout << solution->maximalRectangle(matrix) << endl;
    return 0;
}
