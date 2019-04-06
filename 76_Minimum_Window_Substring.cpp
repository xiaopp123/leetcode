#include "heads.h"
using namespace std;

class Solution {
    public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0 || s.length() < t.length()) {
            return "";
        }
        map<char, int> hash_t;
        map<char, int> visit_t;
        for (int i = 0; i < (int)t.length(); i++) {
            if (hash_t.count(t[i]) == 0) {
                hash_t[t[i]] = 1;
            } else {
                hash_t[t[i]]++;
            }
            visit_t[t[i]] = 0;
        }
        int first, last;
        first = last = 0;
        int required = hash_t.size();
        int formed = 0;
        int res, head_res, tail_res;
        res = (int)s.length() + 1;
        head_res = tail_res = 0;

        while (last < (int)s.length()) {
            if (hash_t.count(s[last]) > 0) {
                visit_t[s[last]]++;
                if (visit_t[s[last]] == hash_t[s[last]]) {
                    formed++;
                }
            }

            while (first <= last && required == formed) {

                if (res > last - first + 1) {
                    res = last - first + 1;
                    head_res = first;
                    tail_res = last;
                }

                if (visit_t.count(s[first]) > 0) {
                    visit_t[s[first]]--;
                    if (visit_t[s[first]] < hash_t[s[first]]) {
                        formed--;
                    }
                }
                first++;
            }
            last++;
        }
        if (res == (int)s.length() + 1) {
            return "";
        }
        return s.substr(head_res, res);
    }
};

/*
class Solution {
    public:
    string minWindow(string s, string t) {
        vector<int> hash_t(256, 0);
        vector<int> visit_t(256, 0);
        int first, last, cnt, res, T;
        first = last = cnt = T = 0;
        res = INT_MAX;
        for (int i = 0; i < (int)t.length(); i++) {
            hash_t[t[i] - 'A'] = 1;
        }
        for (int i = 0; i < (int)hash_t.size(); i++) {
            if (hash_t[i] == 1) {
                T++;
            }
        }
        for (int i = 0; i < (int)s.length(); i++) {
            if (hash_t[s[i] - 'A']) {
                cnt++;
                first = last = i;
                break;
            }
        }
        int head_res, tail_res;
        head_res = 0;
        tail_res = s.length();
        while (first <= last && last < (int)s.length()) {
            visit_t[s[first] - 'A'] = 1;
            last++;
            while (last < (int)s.length() && cnt < T) {
                if (hash_t[s[last] - 'A'] == 1 && visit_t[s[last] - 'A'] == 0) {
                    cnt++;
                    visit_t[s[last] - 'A'] = 1;
                    if (cnt == T) {
                        break;
                    }
                }
                last++;
            }

            if (res > last - first + 1) {
                res = last - first + 1;
                head_res = first;
                tail_res = last;
            }

            cnt--;
            visit_t[s[first] - 'A'] = 0;
            while (first <= last) {
                first++;
                if (hash_t[s[first] - 'A'] == 1) {
                    visit_t[s[first] - 'A'] = 1;
                    break;
                }
            }
        }
        return s.substr(head_res, tail_res - head_res + 1);
    }
};
*/

int main() {
    Solution* solution = new Solution();
    string s, t;
    cin >> s >> t;
    cout << solution->minWindow(s, t) << endl;
    return 0;
}
