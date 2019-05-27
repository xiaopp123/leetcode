#include "heads.h"
using namespace std;
class Solution {
    public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        int duplicate = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            duplicate = 1;
            for (int j = i + 1; j < n; j++) {
                //if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                //    duplicate++;
                //    continue;
                //}
                cnt = 0;
                for (int k = 0; k < n; k++) {
                    long long ax = points[i][0];
                    long long ay = points[i][1];
                    long long bx = points[j][0];
                    long long by = points[j][1];
                    long long cx = points[k][0];
                    long long cy = points[k][1];
                    if (ax * by + cx * ay + bx * cy - cx * by - ax * cy - bx * ay == 0) {
                        cnt++;
                    }
                }
                res = max(res, cnt);
            }
            //res = max(res, duplicate);
        }
        return res;
    }
};

/*
class Solution {
    public:
    int maxPoints(vector<vector<int>>& points) {
        int duplicate = 0;
        int res = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> mp;
            mp.clear();
            duplicate = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    duplicate++;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = GCD(dx, dy);
                mp[{dx / d, dy / d}]++;
            }
            res = max(res, duplicate);
            for (auto it = mp.begin(); it != mp.end(); it++) {
                res = max(res, duplicate + it->second);
            }
        }

        return res;
    }
    int GCD(int a, int b) {
        return b == 0 ? a : GCD(b, a % b);
    }
};
*/

int main() {

    return 0;
}
