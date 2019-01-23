#include "heads.h"
using namespace std;

/**
 * 不同的字母表示不同的任务，要求相同的任务之间至少要有n个间隔，题意一直没搞明白
 *
 * 思路：
 * 去找出现频次最高的任务，优先安排这个，
 * (max_frequent - 1) * (n + 1) + kind
 * 还有一种情况就是间隔为0这样，结果就是task的长度
 */
class Solution {
    public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> g(26,0);
        for (int i = 0; i < (int)tasks.size(); i++) {
            g[tasks[i] - 'A']++;
        }
        sort(g.begin(), g.end());
        int index = 25;
        while (index >= 0 && g[index] == g[25]) {
            index--;
        }
        return max((int)tasks.size(), (g[25] - 1) * (n + 1) + (25 - index));
    }
};
/*
class Solution {
    public:
    static bool cmp(const pair<char, int> a, const pair<char, int> b) {
        return a.second > b.second;
    }
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> g;
        for (int i = 0; i < (int)tasks.size(); i++) {
            g[tasks[i]]++;
        }
        map<char, int>::iterator iter;
        vector<pair<char, int> > vg;
        for (iter = g.begin(); iter != g.end(); iter++) {
            vg.push_back(make_pair(iter->first, iter->second));
        }
        sort(vg.begin(), vg.end(), cmp);
        int max_frequent = vg[0].second;
        int num = 1;
        for (int i = 1; i < (int)vg.size(); i++) {
            if (vg[i].second == max_frequent) {
                num++;
            } else {
                break;
            }
        }

        return max((int)tasks.size(), (max_frequent - 1) * (n + 1) + num);
    }
};
*/

int main() {
    return 0;
}
