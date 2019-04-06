#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if ((int) s.length() == 0 || (int)p.length() == 0 || (int)s.length() < (int)p.length()) {
            return res;
        }
        vector<int> mp(26, 0);
        for (int i = 0; i < (int)p.length(); i++) {
            mp[p[i] - 'a']++;
        }
        int l = 0, r = 0, cnt = p.length();
        while (r < (int)s.length()) {
            if (--mp[s[r++] - 'a'] >= 0) {
                cnt--;
            }
            if (cnt == 0) {
                res.push_back(l);
            }
            if (r - l == (int)p.length() && mp[s[l++] - 'a']++ >= 0) {
                cnt++;
            }
        }

        return res;
    }
};
/*
class Solution {
    public:
    bool cmp(string s, string p, int len) {
        sort(s.begin(), s.end());
        sort(p.begin(), p.end());
        if (s.compare(p) == 0) {
            return true;
        }
        return false;
    }

    vector<int> findAnagrams(string s, string p) {
        int sl = s.length();
        int pl = p.length();
        vector<int> res;
        for (int i = 0; i < sl - pl; i++) {
            if (cmp(s.substr(i, pl), p, pl)) {
                res.push_back(i);
            }
        }

        return res;
    }
};
*/

int main() {
    string s, p;
    while (cin >> s >> p) {
        Solution* solution = new Solution();
        vector<int> res = solution->findAnagrams(s, p);
        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
