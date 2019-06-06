#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> builds;
        for (int i = 0; i < (int)buildings.size(); i++) {
            builds.push_back({buildings[i][0], -buildings[i][2]});
            builds.push_back({buildings[i][1], buildings[i][2]});
        }
        sort(builds.begin(), builds.end());
        vector<vector<int>> res;
        multiset<int> m;
        int cur = 0;
        int pre = 0;
        m.insert(0);

        for (int i = 0; i < (int)builds.size(); i++) {
            if (builds[i].second < 0) {
                m.insert(builds[i].second);
            } else {
                m.erase(m.find(builds[i].second));
            }
            cur = *m.rbegin();

            if (cur != pre) {
                res.push_back({builds[i].first, cur});
                pre = cur;
            }

        }

        return res;
    }
};

int main() {

    return 0;
}
