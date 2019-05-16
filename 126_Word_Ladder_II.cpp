#include "heads.h"
using namespace std;

class Solution {
    public:
    int dfs(int cnt, int cur_cnt, string beginWord, string endWord, map<string, vector<string>>& path, vector<string> cur_res, set<vector<string>>& res) {
        //cout << endWord << endl;
        if (cur_cnt > cnt) {
            return 0;
        }
        if (endWord == beginWord) {
            reverse(cur_res.begin(), cur_res.end());
            res.insert(cur_res);
            return 0;
        }
        if (path.count(endWord) == 0) {
            return 0;
        }
        for (int i = 0; i < (int)path[endWord].size(); i++) {
            //cout <<  path[endWord][i] << endl;
            cur_res.push_back(path[endWord][i]);
            dfs(cnt, cur_cnt + 1, beginWord, path[endWord][i], path, cur_res, res);
            cur_res.pop_back();
        }
        return 0;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dic(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (dic.count(endWord) == 0) {
            return res;
        }
        queue<string> que;
        que.push(beginWord);
        bool flag = false;
        int cnt = 0;
        map<string, vector<string>> path;
        while (!que.empty()) {
            int n = que.size();
            cnt++;
            for (int i = 0; i < n; i++) {
                string tmp = que.front();
                que.pop();
                if (tmp == endWord) {
                    flag = true;
                    continue;
                }
                for (int j = 0; j < (int)tmp.size(); j++) {
                    string new_word = tmp;
                    for (int c = 'a'; c <= 'z'; c++) {
                        new_word[j] = c;
                        if (dic.count(new_word) > 0) {
                            path[new_word].push_back(tmp);
                            que.push(new_word);
                            if (new_word != endWord) {
                                dic.erase(new_word);
                            }
                        }
                    }
                }
            }
            if (flag) {
                break;
            }
        }
        map<string, vector<string>>::iterator it;
        for (it = path.begin(); it != path.end(); it++) {
            cout << it->first << " ";
            for (int i = 0; i < (int)it->second.size(); i++) {
                cout << it->second[i] << " ";
            }
            cout << endl;
        }
        cout << cnt << endl;
        vector<string> cur_res;
        set<vector<string>> res_set;
        cur_res.push_back(endWord);
        dfs(cnt, 0, beginWord, endWord, path, cur_res, res_set);
        set<vector<string>>::iterator iit;
        for (iit = res_set.begin(); iit != res_set.end(); iit++) {
            res.push_back(*iit);
        }

        return res;
    }
};

int main() {
    Solution* solution = new Solution();
    string beginWord = "red";
    string endWord = "tax";
    vector<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
    solution->findLadders(beginWord, endWord, wordList);

    return 0;
}
