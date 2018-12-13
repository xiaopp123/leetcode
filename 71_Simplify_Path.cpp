#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    private:
        vector<string> split(string path, char del) {
            vector<string> path_arr;
            int len = path.length();
            int s = 0;
            for (int i = 0; i < len; i++) {
                if (path[i] == del) {
                    path_arr.push_back(path.substr(s, i - s));
                    s = i + 1;
                }
            }
            if (path[len - 1] != '/') {
                path_arr.push_back(path.substr(s, len - s));
            }

            return path_arr;
        }
    public:
    string simplifyPath(string path) {
        vector<string> path_arr;
        path_arr = split(path, '/');
       // for (int i = 0; i < (int)path_arr.size(); i++) {
       //     cout << path_arr[i] << " ";
       // }
       // cout << endl;
        stack<string> st;
        for (int i = 0; i < (int)path_arr.size(); i++) {
            string cur = path_arr[i];
            if (cur.compare(".") == 0 || cur.compare("") == 0) {
                continue;
            } else if (cur.compare("..") == 0) {
                if (st.size() > 0) {
                    st.pop();
                }
            } else {
                st.push(cur);
            }
        }
        string res = "";
        if (!st.empty()) {
            res = st.top();
            st.pop();
        }
        while (!st.empty()) {
            res = st.top() + "/" + res;
            st.pop();
        }

        return "/" + res;

    }
};

int main() {
    string path;
    while (cin >> path) {
        Solution* solution = new Solution();
        cout << solution->simplifyPath(path) << endl;
    }

    return 0;
}
