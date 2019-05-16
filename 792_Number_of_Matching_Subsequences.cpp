#include "heads.h"
using namespace std;

class Solution {
    public:
    int numMatchingSubseq(string S, vector<string>& words) {
        map<char, vector<int>> char_dict;
        for (int i = 0; i < (int)S.length(); i++) {
            char_dict[S[i]].push_back(i);
        }
        int res = 0;
        for (int i = 0; i < (int)words.size(); i++) {
            int pre = -1;
            bool flag = true;
            for (int j = 0; j < (int)words[i].length(); j++) {
                auto it = upper_bound(char_dict[words[i][j]].begin(), char_dict[words[i][j]].end(), pre);
                if (it == char_dict[words[i][j]].end()) {
                    flag = false;
                    break;
                }
                pre = *it;
            }
            if (flag) {
                res++;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
