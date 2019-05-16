#include "heads.h"
using namespace std;

class Solution {
    public:
    bool can_trans(string src, string dst) {
        int len = src.length();
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (src[i] != dst[i]) {
                cnt++;
            }
        }
        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dic(wordList.begin(), wordList.end());
        if (dic.count(endWord) == 0) {
            return 0;
        }
        queue<string> que;
        que.push(beginWord);
        int res = 0;
        set<string> visit;
        while (!que.empty()) {
            res++;
            int n = que.size();
            for (int i = 0; i < n; i++) {
                string tmp = que.front();
                que.pop();
                if (tmp == endWord) {
                    return res;
                }
                for (int j = 0; j < (int)tmp.size(); j++) {
                    string new_word = tmp;
                    for (int c = 'a'; c <= 'z'; c++) {
                        new_word[j] = c;
                        if (dic.count(new_word) > 0) {
                            que.push(new_word);
                            dic.erase(new_word);
                        }
                    }
                }
            }
        }

        return 0;
    }
};

int main() {

    return 0;
}
