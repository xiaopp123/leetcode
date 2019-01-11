#include "heads.h"

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int k = 0;
        //k是引用的
        return dfs(s, k);
    }
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

int main() {
    return 0;
}
