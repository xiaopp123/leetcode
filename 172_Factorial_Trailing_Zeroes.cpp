#include "heads.h"
using namespace std;

class Solution {
    public:
    int trailingZeroes(int n) {
        int cnt = 0;
        long long res = 1;
        for (int i = n; i > 0; i++) {
            res = res * i;
            while (res % 10 == 0) {
                cnt++;
                res /= 10;
            }
        }
        return cnt;
    }
};

int main() {
    return 0;
}
