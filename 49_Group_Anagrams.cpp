#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/group-anagrams/description/
 * 总体的思路就是 hash，有两种hash的方式
 * 1、对字符串排序，需要对每一个字符串都要进行排序，复杂度优点高
 * 2、hash成计数的串
 */
class Solution {
    public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        int n = strs.size();
        if (n == 0) {
            return res;
        }

        map<string, vector<string> > graph;
        int cnt[26];
        for (int i = 0; i < n; i++) {
            string strItem = strs[i];
            memset(cnt, 0, sizeof(cnt));
            for (int j = 0; j < (int)strItem.length(); j++) {
                cnt[strItem[j] - 'a']++;
            }
            string keyStr;
            for (int j = 0; j < 26; j++) {
                keyStr += '#' + cnt[j];
            }
            if (graph.count(keyStr) > 0) {
                graph[keyStr].push_back(strItem);
            } else {
                vector<string> strItemVec;
                strItemVec.push_back(strItem);
                graph.insert(pair<string, vector<string> > (keyStr, strItemVec));
                //graph[keyStr] = strItem;
            }
        }

        map<string, vector<string> > :: iterator it;
        for (it = graph.begin(); it != graph.end(); it++) {
            res.push_back(it->second);
        }

        return res;
    }
};

int main() {
    return 0;
}
