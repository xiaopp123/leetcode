#include "heads.h"
using namespace std;

class Solution {
    public:
    int numTrees(int n) {
        int f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                f[i] += (f[k - 1] * f[i - k]);
            }
        }
        return f[n];
    }
};

int main() {
    Solution* solution = new Solution();
    int n;
    while (cin >> n) {
        cout << solution->numTrees(n) << endl;
    }
    return 0;
}
