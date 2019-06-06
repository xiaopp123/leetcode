#include "heads.h"
using namespace std;

class Solution {
    public:
    int helper(int n) {
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        set<int> hs;
        int sum = n;
        while (true) {
            sum = helper(sum);
            if (hs.count(sum) || sum == 1) {
                return sum == 1 ? true : false;
            }
            hs.insert(sum);
        }
        return sum == 1 ? true : false;
    }
};

int main() {

    return 0;
}
