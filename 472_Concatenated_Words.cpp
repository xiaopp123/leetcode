#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> st(words.begin(), words.end());
        vector<string> res;
        for (string word : words) {
            int len = word.length();
            if (len == 0) {
                continue;
            }
            vector<bool> dp(len + 1, false);
            dp[0] = true;
            for (int i = 0; i < len; i++) {
                if (!dp[i]) {
                    continue;
                }
                for (int j = i + 1; j <= len; j++) {
                    if (j - i < len && st.count(word.substr(i, j - i)) > 0) {
                        dp[j] = true;
                        break;
                    }
                }
                if (dp[len]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};

/*
class Solution {
    public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> st(words.begin(), words.end());
        vector<string> res;
        for (int i = 0; i < (int)words.size(); i++) {
            if (words[i].length() <= 0) {
                continue;
            }
            st.erase(words[i]);
            vector<bool> dp(words[i].length() + 1, 0);
            dp[0] = 1;
            for (int j = 0; j < (int)words[i].length() + 1; j++) {
                for (int k = 0; k < j; k++) {
                   if (dp[k] && st.count(words[i].substr(k, j - k)) > 0) {
                       dp[j] = 1;
                       break;
                   }
                }
            }
            if (dp[words[i].length()] == 1) {
                res.push_back(words[i]);
            }
            st.insert(words[i]);
        }
        return res;
    }
};
*/

int main() {
    return 0;
}
