#include "heads.h"
using namespace std;
class Solution {
    public:
    vector<string> removeInvalidParentheses(string s) {
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            cnt1 += (s[i] == '(');
            if (cnt1 == 0) {
                cnt2 += (s[i] == ')');
            } else {
                cnt1--;
            }
        }
        vector<string> res;
        dfs(s, 0, cnt1, cnt2, res);
        return res;
    }
    void dfs(string s, int start, int cnt1, int cnt2, vector<string>& res) {
        if (cnt1 == 0 && cnt2 == 0) {
            res.push_back(s);
            return;
        }
        for (int i = start; i < (int)s.size(); i++) {
            if (i != start && s[i] == s[i - 1]) {
                continue;
            }
            if (cnt1 > 0 && s[i] == '(') {
                dfs(s.substr(0, i) + s.substr(i + 1), i, cnt1 - 1, cnt2, res);
            }
            if (cnt2 > 0 && s[i] == ')') {
                dfs(s.substr(0, i) + s.substr(i + 1), i, cnt1, cnt2 - 1, res);
            }
        }
    }
};

/*
class Solution {
    public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> que;
        que.push(s);
        vector<string> res;
        set<string> visited;
        visited.insert(s);
        bool found = false;
        while (!que.empty()) {
            string str = que.front();
            que.pop();
            if (is_valid(str)) {
                res.push_back(str);
                found = true;
            }
            if (found) {
                continue;
            }
            for (int i = 0; i < (int)str.size(); i++) {
                if (str[i] != '(' && str[i] != ')') {
                    continue;
                }
                string temp = str.substr(0, i) + str.substr(i + 1);
                if (visited.count(temp) > 0) {
                    continue;
                }
                visited.insert(temp);
                que.push(temp);
            }

        }
        return res;
    }

    bool is_valid(string str) {
        int cnt = 0;
        for (int i = 0; i < (int)str.length(); i++) {
            if (str[i] == '(') {
                cnt++;
            } else if (str[i] == ')') {
                cnt--;
                if (cnt < 0) {
                    return false;
                }
            }
        }
        return cnt == 0;
    }
};
*/

int main() {
    return 0;
}
