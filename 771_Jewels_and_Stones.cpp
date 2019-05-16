#include "heads.h"
using namespace std;

class Solution {
    public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        set<char> char_dict;
        for (int i = 0; i < (int)J.length(); i++) {
            char_dict.insert(J[i]);
        }
        for (int i = 0; i < (int)S.length(); i++) {
            if (char_dict.count(S[i]) > 0) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
