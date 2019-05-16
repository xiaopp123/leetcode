#include "heads.h"
#include <unordered_set>

using namespace std;
class Solution {
    public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> mem(s.size(), -1);
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());

        return check(s, wordset, 0, mem);
    }
    bool check(string s, unordered_set<string>& wordset, int start, vector<int>& mem) {
        if (start >= (int)s.size()) {
            return true;
        }
        if (mem[start] != -1) {
            return mem[start];
        }
        for (int i = start + 1; i <= (int)s.size(); i++) {
            if (wordset.count(s.substr(start, i - start)) && check(s, wordset, i, mem)) {
                return mem[start] = 1;
            }
        }
        return mem[start] = 0;
    }
};


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
