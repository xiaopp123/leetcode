#include "heads.h"
using namespace std;

class Solution {
    public:
    int longestSubstring(string s, int k) {
        int mask = 0;
        int i = 0;
        int res = 0;
        int n = s.length();
        while (i + k < n) {
            int m[26] = {0};
            mask = 0;
            for (int j = i; j < n; j++) {
                int t = s[j] - 'a';
                m[t]++;
                if (m[t] < k) {
                    mask |= (1 << t);
                } else {
                    mask &= (~(1 << t));
                }
                if (mask == 0) {
                    res = max(res, j - i + 1);
                }
            }
            i++;
        }

        return res;
    }
};

int main() {
    return 0;
}
