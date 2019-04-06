#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
        static bool cmp(Interval &a, Interval &b) {
            return a.start < b.start;
        }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int len = intervals.size();
        if (len == 0) {
            return res;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int s = intervals[0].start;
        int e = intervals[0].end;
        for (int i = 1; i < len; i++) {
            if (intervals[i].start <= e) {
                e = max(e, intervals[i].end);
                continue;
            }
            Interval resItem = Interval(s, e);
            res.push_back(resItem);
            s = intervals[i].start;
            e = intervals[i].end;
        }

        res.push_back(Interval(s, e));

        return res;
    }
};
int main() {

    return 0;
}
