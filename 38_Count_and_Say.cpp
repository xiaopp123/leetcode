#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    private:
        vector<string> res;

    public:
    string countAndSay(int n) {
        res.push_back("1");
        for (int i = 1; i < n; i++) {
            getNext(res[i - 1]);
        }
        return res[n - 1];
    }

    public:
    void getNext(string last) {
        int k = 1;
        int len = (int) last.length();
        string cur;
        //cout << last << endl;
        for (int i = 0; i < len - 1; i++) {
            if (last[i] == last[i + 1]) {
                k++;
            } else {
                cur += (k + '0');
                cur += last[i];
                k = 1;
            }
        }
        cur += (k + '0');
        cur += last[len - 1];
        res.push_back(cur);
    }
};

int main() {
    int n;
    while (cin >> n) {
        Solution* solution = new Solution();
        cout << solution->countAndSay(n) << endl;
    }
    return 0;
}
