#include "heads.h"
using namespace std;

class Solution {
    public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 0) {
            return 0;
        }
        vector<pair<int, int>> psets;
        for (int i = 0; i < (int)pairs.size(); i++) {
            psets.push_back(make_pair(pairs[i][0], pairs[i][1]));
        }
        sort(psets.begin(), psets.end(), cmp);
        int res = 1;
        int end = psets[0].second;
        for (int i = 1; i < psets.size(); i++) {
            if (end < psets[i].first) {
                end = psets[i].second;
                res++;
            } else {
                continue;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
