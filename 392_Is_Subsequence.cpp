#include "heads.h"
using namespace std;

class Solution {
    public:
    bool isSubsequence(string s, string t) {
        map<char, vector<int>> char_dict;
        for (int i = 0; i < (int)t.length(); i++) {
            char_dict[t[i]].push_back(i);
        }
        int pre = -1;
        for (int i = 0; i < (int)s.length(); i++) {
            auto it = upper_bound(char_dict[s[i]].begin(), char_dict[s[i]].end(), pre);
            if (it == char_dict[s[i]].end()) {
                return false;
            }
            pre = *it;
        }
        return true;
    }
};

int main() {
    return 0;
}
