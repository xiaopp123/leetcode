#include "heads.h"
using namespace std;

/*
class Solution {
    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<int, vector<string>> dict;
        dict[0].push_back("");
        for (int i = 1; i <= (int)s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dict.count(j) > 0 && (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())) {
                    auto it = find(wordDict.begin(), wordDict.end(), s.substr(j, i - j));
                    vector<string> cur = dict[j];
                    for (int k = 0; k < (int)cur.size(); k++) {
                        if (j == 0) {
                            dict[i].push_back(*it);
                        } else {
                            dict[i].push_back(cur[k] + " " + *it);
                        }
                    }
                }
            }
        }
        return dict[s.length()];
    }
};
*/
/*
class Solution {
    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, vector<string>> m;
        helper(s, wordDict, m);
        return m[s];
    }
    vector<string> helper(string s, vector<string>& wordDict, map<string, vector<string>>& m) {
        if (m.count(s) > 0) {
            return m[s];
        }
        if (s.empty()) {
            return {""};
        }
        for (int i = 0; i < (int)wordDict.size(); i++) {
            if (s.substr(0, (int)wordDict[i].length()) == wordDict[i]) {
                vector<string> res = helper(s.substr((int)wordDict[i].length()), wordDict, m);
                for (int j = 0; j < (int)res.size(); j++) {
                    m[s].push_back(wordDict[i] + (res[j] == "" ? "" : " ") + res[j]);
                }
            }
        }

        return m[s];
    }
};
*/

class Solution {
    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string str;
        map<string, vector<string>> mp;
        dfs(0, s, wordDict, mp);
        return mp[s];
    }
    int dfs(int cur, string s, vector<string>& wordDict, map<string, vector<string>>& mp) {
        if (cur >= (int)s.length()) {
            mp[s.substr(cur)] = {""};
            return 0;
        }
        if (mp.count(s.substr(cur)) > 0) {
            return 0;
        }
        for (int l = 1; l <= (int)s.length() - cur; l++) {
            auto it = find(wordDict.begin(), wordDict.end(), s.substr(cur, l));
            if (it == wordDict.end()) {
                continue;
            }
            dfs(cur + l, s, wordDict, mp);
            for (int j = 0; j < (int)mp[s.substr(cur + l)].size(); j++) {
                mp[s.substr(cur)].push_back(*it + (cur + l < (int)s.length() ? " " + mp[s.substr(cur + l)][j]: ""));
            }
        }
        return 0;
    }
};

int main() {
    Solution* solution = new Solution();
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> wordDict;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        wordDict.push_back(t);
    }
    solution->wordBreak(s, wordDict);
    return 0;
}
