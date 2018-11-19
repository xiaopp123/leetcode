#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
    int strStr(string haystack, string needle) {
        int lenH = haystack.length();
        int lenN = needle.length();
        if (lenN == 0) {
            return 0;
        }
        int *next = getNext(needle);

        int i = 0, j = 0;
        while (i < lenH && j < lenN ) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == lenN) {
            return i - j;
        } else {
            return -1;
        }
    }

    private:
    int* getNext(string needle) {
        int n = needle.length();
        int *next = new int[n];
        next[0] = -1;
        int i = 0;
        int k = -1;
        while (i < n - 1) {
            if (k == -1 || needle[i] == needle[k]) {
                next[++i] = ++k;
            } else {
                k = next[k];
            }
        }

        return next;
    }
};

int main() {
    string haystack, needle;
    Solution *solution = new Solution();
    while (cin >> haystack >> needle) {
        cout << solution->strStr(haystack, needle) << endl;
    }
    return 0;
}
