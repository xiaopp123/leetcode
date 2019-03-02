#include "heads.h"

using namespace std;

class Solution {
    public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        //其中res[i] 表示区间[0,i)是否可以分割
        vector<bool> res(len + 1, 0);
        res[0] = true;
        for (int i = 1; i < len + 1; i++) {
            for (int j = 0; j < i; j++) {
                if(res[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    res[i] = true;
                    break;
                }
            }
        }
        return res[len];
    }
};

int main() {
    return 0;
}
