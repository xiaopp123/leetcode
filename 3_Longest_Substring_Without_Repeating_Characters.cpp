#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
         * 滑动窗口解法
         */
        int len = s.length();
        int start, end;
        start = end = 0;
        int maxLen = 0;
        //[start，end]这个区间保证没有重复的元素，
       // if (len > 0) {
       //     maxLen = 1;
       // }
       // set<char> charSet;
       // while (start < len && end < len) {
       //     if (charSet.count(s[end]) == 0) {
       //         charSet.insert(s[end]);
       //         maxLen = max(maxLen, (int) charSet.size());
       //         end++;
       //     } else {
       //         charSet.erase(s[start++]);
       //     }
       // }
        int j = 0;
        map<char, int> charMap;
        for (int i = 0; i < len; i++) {
            if (charMap.count(s[i]) == 0) {
                charMap[s[i]] = i + 1;
                maxLen = max(maxLen, i - j + 1);
            } else {
                j = max(charMap[s[i]], j);
                charMap[s[i]] = i + 1;
            }
        }

        return maxLen;
    }
};
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int len = s.length();
//        bool flag[257];
//        int maxLen = 1;
//        memset(flag, false, sizeof(flag));
//
//        for (int i = 0; i < len; i++) {
//            memset(flag, false, sizeof(flag));
//            flag[int(s[i])] = true;
//            for (int j = i + 1; j < len; j++) {
//                if (flag[int(s[j])]) {
//                    break;
//                }
//                flag[int(s[j])] = true;
//                maxLen = max(maxLen, j - i + 1);
//            }
//        }
//
//        return maxLen;
//    }
//};

int main() {

    Solution* solution = new Solution();
    string s;
    cin >> s;
    cout << solution->lengthOfLongestSubstring(s) << endl;

    return 0;
}
