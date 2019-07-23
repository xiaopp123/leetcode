#include "heads.h"

using namespace std;
class Solution {
public:
    string decodeString(string s) {
    }
};

class Solution {
public:
    string decodeString(string s) {
        int k = 0;
        return dfs(s, k);
    }
    string dfs(string s, int & k) {
        string res = "";
        while (k < (int)s.length()) {
            if ((s[k] >= 'a' && s[k] <= 'z') || (s[k] >= 'A' && s[k] <= 'Z')) {
                res += s[k++];
            } else if (s[k] == ']') {
                break;
            } else {
                int num = 0;
                while (s[k] >= '0' && s[k] <= '9') {
                    num = num * 10 + s[k] - '0';
                    k++;
                }
                k++;
                string sub_layer = dfs(s, k);
                //返回时k还在]位置上h
                k++;

                while (num-- > 0) {
                    res += sub_layer;
                }
            }
        }

        return res;
    }
};

/*
class Solution {
public:
    string decodeString(string s) {
        int k = 0;
        //k是引用的
        return dfs(s, k); }
    string dfs(string s, int& k) {
        string res;
        int cnt = 0;
        while (k < (int)s.size()) {
            if (isdigit(s[k])) {
                cnt = cnt * 10 + (s[k++] - '0');
            } else if (s[k] == '[') {
                string next_layer;
                next_layer = dfs(s, ++k);
                for (int i = 0; i < cnt; i++) {
                    res += next_layer;
                }
                //这个一定注意
                cnt = 0;
            } else if (s[k] == ']') {
                k++;
                return res;
            } else {
                res += s[k++];
            }
        }
        return res;
    }
};
*/

int main() {
    return 0;
}
