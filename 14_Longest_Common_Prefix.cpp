#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    /**
    public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        int str_nums = strs.size();
        if (str_nums == 0) {
            return strs[0];
        }
        int len = strs[0].length();
        for (int i = 1; i < str_nums; i++) {
            len = min(len, (int)strs[i].length());
        }
        int res = len;
        char first_str;
        bool flag = true;
        for (int i = 0; i < len; i++) {
            first_str = strs[0][i];
            for (int j = 1; j < str_nums; j++) {
                if (first_str != strs[j][i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                res = i;
                break;
            }
        }
        string result = "";
        for (int i = 0; i < res; i++) {
            result += strs[0][i];
        }

        return result;
    }
    */
    /**
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) {
                return "";
            }
            if (strs.size() == 1) {
                return strs[0];
            }

            return LCP(strs, 0, strs.size() - 1);
    }
    private:
        string LCP(vector<string>& strs, int l, int r) {
            if (l == r) {
                return strs[l];
            }
            else {
                int mid = (l + r) / 2;
                string leftString = LCP(strs, l, mid);
                string rightString = LCP(strs, mid + 1, r);

                return commonPrefix(leftString, rightString);
            }
        }

    private:
        string commonPrefix(string leftString, string rightString) {
            if (leftString[0] != rightString[0]) {
                return "";
            }
            int len = min(leftString.length(), rightString.length());
            for (int i = 0; i < len; i++) {
                if (leftString[i] != rightString[i]) {
                    return leftString.substr(0, i);
                }
            }

            return leftString.substr(0, len);
        }
    */
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) {
                return "";
            }
            int str_nums = strs.size();
            if (str_nums == 1) {
                return strs[0];
            }
            int len = strs[0].length();
            for (int i = 1; i < str_nums; i++) {
                len = min(len, (int)strs[i].length());
            }

            int l = 0, r = len;

            while (l < r) {
                int mid = (l + r) / 2;
                if (isCommon(strs, mid)) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            return strs[0].substr(0, l);
        }

    private:
        bool isCommon(vector<string>& strs, int len) {
            string str = strs[0].substr(0, len + 1);
            for (int i = 1; i < (int)strs.size(); i++) {
                if (!isStartWith(str, strs[i], len)) {
                    return false;
                }
            }

            return true;
        }

    private:
        bool isStartWith(string str1, string str2, int len) {
            for (int i = 0; i <= len; i++) {
                if (str1[i] != str2[i]) {
                    return false;
                }
            }

            return true;
        }
};

int main() {
    Solution* solution = new Solution();
    vector<string> strs;
    string str;
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> str;
            strs.push_back(str);
        }
        cout << solution->longestCommonPrefix(strs) << endl;
    }

    return 0;
}
