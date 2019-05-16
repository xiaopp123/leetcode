#include "heads.h"
using namespace std;
class Solution {
    public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
/*
class Solution {
    public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (i - 2 >= 0) {
                    triangle[i - 1][j] += min(j == i - 1 ? INT_MAX : triangle[i - 2][j], j - 1 >= 0 ? triangle[i - 2][j - 1] : INT_MAX);
                }
            }
        }
        int res = INT_MAX;
        for (int j = 0; j < n; j++) {
            res = min(triangle[n - 1][j], res);
        }
        return res;
    }
};
*/

int main() {
    vector<vector<int>> triangle;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int> item;
        item.clear();
        for (int j = 0; j < i; j++) {
            int t;
            cin >> t;
            item.push_back(t);
        }
        triangle.push_back(item);
    }
    Solution* solution = new Solution();
    cout << solution->minimumTotal(triangle) << endl;

    return 0;
}
