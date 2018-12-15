#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    private:
        int find_first(vector<int> arry, int left, int right, int target) {
            int l = left, r = right;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (arry[mid] <= target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return r - 1;
        }
    public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = (int) matrix.size();
        if (m == 0) {
            return false;
        }
        int n = (int) matrix[0].size();
        if (n == 0) {
            return false;
        }
        vector<int> col;
        for (int i = 0; i < m; i++) {
            col.push_back(matrix[i][0]);
        }
        int r = find_first(col, 0, m, target);
        if (r < 0 || r >= m) {
            return false;
        }
        if (col[r] == target) {
            return true;
        }
        int c = find_first(matrix[r], 1, n, target);
        if (c < 1 || c >= n) {
            return false;
        }
        if (matrix[r][c] == target) {
            return true;
        }
        return false;
    }
};

int main() {
    int m, n;
    vector<vector<int> > matrix;
    int target;
    while (cin >> m >> n >> target) {
        for (int i = 0; i < m; i++) {
            vector<int> row;
            for (int j = 0; j < n; j++) {
                int t;
                cin >> t;
                row.push_back(t);
            }
            matrix.push_back(row);
        }
        Solution* solution = new Solution();
        cout << solution->searchMatrix(matrix, target) << endl;
    }
    return 0;
}
