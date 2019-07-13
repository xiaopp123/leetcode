#include "heads.h"
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int len = s.length();
        string s_clean;
        for (int i = 0; i < len; i++) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s_clean += (s[i] - 'A' + 'a');
                } else {
                    s_clean += s[i];
                }
            }
        }
        len = s_clean.length();
        for (int i = 0; i < len / 2; i++) {
            if (s_clean[i] != s_clean[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
