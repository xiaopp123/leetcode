#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
    public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        set<int> rows;
        set<int> col;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    col.insert(j);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (rows.count(i) > 0) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (col.count(j) > 0) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    return 0;
}
