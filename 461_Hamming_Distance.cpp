#include "heads.h"
using namespace std;

class Solution {
    public:
    int hammingDistance(int x, int y) {
        int xy = x ^ y;
        int res = 0;
        while (xy > 0) {
            if (xy & 1) {
                res++;
            }
            xy >>= 1;
        }
        return res;
    }
};

int main() {
    Solution* solution = new Solution();
    int x, y;
    while (cin >> x >> y) {
        cout << solution->hammingDistance(x, y) << endl;
    }
    return 0;
}
