#include "heads.h"
using namespace std;
class Solution {
    public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < (int)s.length(); i += 2 * k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};

class Solution {
    public:
    string reverseStr(string s, int k) {
        int start = 0;
        int len = s.length();
        bool flag = true;
        while (start + k <= len) {
            if (flag) {
                reverse(s.begin() + start, s.begin() + start + k);
            }
            flag = !flag;
            start += k;
        }
        if (start + k > len) {
            if (flag) {
                reverse(s.begin() + start, s.end());
            }
        }
        return s;
    }
};

int main() {
    return 0;
}
