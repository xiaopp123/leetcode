#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <limits.h>
using namespace std;

/**
 * bfs
 * 超时
class Solution {
    public:
    int jump(vector<int>& nums) {
        pair<int, int> node(0, 0);
        queue<pair<int, int> > que;
        que.push(node);
        int vis[nums.size()];
        for (int i = 0; i < (int)nums.size(); i++) {
            vis[i] = INT_MAX;
        }
        vis[0] = 0;

        while (!que.empty()) {
            node = que.front();
            que.pop();
            if (node.first == (int)nums.size() - 1) {
                return node.second;
            }
            int step = nums[node.first];
            for (int i = 1; i <= step; i++) {
                if (node.first + i < (int)nums.size()) {
                    pair<int, int> next;
                    if (vis[node.first] + 1 < vis[node.first + i]) {
                        next.first = node.first + i;
                        next.second = node.second + 1;
                        vis[node.first + i] = vis[node.first] + 1;

                        que.push(next);
                    }
                }
            }
        }
    }

};
*/
/*
class Solution {
    public:
    int jump(vector<int>& nums) {
        int len = (int)nums.size();
        int res[len];
        for (int i = 0; i < len; i++) {
            res[i] = INT_MAX;
        }
        res[len - 1] = 0;
        for (int i = len - 1; i >= 0; i--) {
            int step = min(i + nums[i], len - 1);
            for (int j = i + 1; j <= step; j++) {
                if (res[j] < INT_MAX) {
                    res[i] = min(res[i], res[j] + 1);
                }
            }
        }
        return res[0];
    }
};
*/
/*
class Solution {
    public:
    int jump(vector<int>& nums) {
        int res = 0;
        int len = (int)nums.size();
        int cur = 0, index = 0;
        while (cur < len - 1) {
            int pre = cur;
            while (index <= pre) {
                cur = max(cur, index + nums[index]);
                index++;
            }
            if (pre == cur) return -1;
            res++;
        }

        return res;
    }
};
*/
class Solution {
    public:
    int jump(vector<int>& nums) {
        int last = 0;
        int cur = 0;
        int res = 0;
        int len = (int) nums.size();
        for (int i = 0; i < len - 1; i++) {
            cur = max(cur, i + nums[i]);
            if (i == last) {
                res++;
                last = cur;
                if (cur >= len - 1) {
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        Solution* solution = new Solution();
        cout << solution->jump(nums) << endl;
    }

    return 0;
}
