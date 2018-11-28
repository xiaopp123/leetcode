#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

//这种方法应该做错了
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        if (p.length() == 0) {
//            return s.length() == 0;
//        }
//        if (p.length() == 1 && p[0] == '*') {
//            return true;
//        }
//
//        bool firstMatch = s.length() > 0 && (s[0] == p[0] || p[0] == '?');
//
//        if (s.length() > 0 && p[0] == '*') {
//            return isMatch(s.substr(1), p) || (isMatch(s, p.substr(1)));
//        }
//
//        return firstMatch && isMatch(s.substr(1), p.substr(1));
//    }
//};
//广度优先遍历

//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        // nums存放要匹配的s的位置，初始化为0
//        set<int> nums;
//        nums.insert(0);
//        //对p的每个位置进行枚举，看它能匹配到s的什么位置
//        for (int i = 0; i < (int)p.length(); i++) {
//            set<int> next;
//            set<int> :: iterator it;
//            //nums里是待匹配的位置
//            for (it = nums.begin(); it != nums.end(); it++) {
//                int pos = *it;
//                //如果是*，表示当前到最后都能匹配上
//                if (p[i] == '*') {
//                    for (int j = pos; j <= (int)s.length(); j++) {
//                        next.insert(j);
//                    }
//                } else if (p[i] == '?') {
//                    //如果是？表示当前能匹配上
//                    next.insert(pos + 1);
//                } else {
//                    if (pos < (int)s.length() && p[i] == s[pos]) {
//                        next.insert(pos + 1);
//                    }
//                }
//            }
//            nums = next;
//        }
//
//        return nums.count(s.length()) > 0;
//    }
//};

class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        bool dp[lenp + 1][lens + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= lenp; i++) {
            dp[i][0] = p[i - 1] == '*' && dp[i - 1][0];
            for (int j = 1; j <= lens; j++) {
                if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else if (p[i - 1] == '?' || p[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[lenp][lens];
    }

};



int main() {
    Solution* solution = new Solution();
    string s, p;
    while (cin >> s >> p) {
        cout << solution->isMatch(s, p) << endl;
    }

    return 0;
}
