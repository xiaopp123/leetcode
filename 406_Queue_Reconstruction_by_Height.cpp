#include "heads.h"

using namespace std;

class Solution {
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                            return a.first > b.first || (a.first == b.first && a.second < b.second);
                                    });
        vector<pair<int, int> > res;
        //for (int i = 0; i < (int)people.size(); i++) {
        //    res.insert(res.begin() + people[i].second, people[i]);
        //}
        for (auto p: people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};

int main() {
    int n;
    while (cin >> n) {
        Solution* solution = new Solution();
        vector<pair<int, int> > people;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            people.push_back(make_pair(a, b));
        }
        vector<pair<int, int> > res = solution->reconstructQueue(people);
        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i].first << " " << res[i].second << endl;
        }
        cout << endl;
    }
    return 0;
}
