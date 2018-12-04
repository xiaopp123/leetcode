#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int xDir[4] = {0, 1, -1, 0};
        int yDir[4] = {1, 0, 0, -1};
        int R = matrix.size();
        if (R == 0) {
            return res;
        }
        int C = matrix[0].size();
        int r = 0, c = 0, d = 0;
        bool vis[R][C];
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < R * C; i++) {
            res.push_back(matrix[r][c]);
            vis[r][c] = true;
            int nr = r + xDir[d];
            int nc = c + yDir[d];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && !vis[nr][nc]) {
                r = nr;
                c = nc;
            } else {
                d = (d + 1) % 4;
                r = r + xDir[d];
                c = c + yDir[d];
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
