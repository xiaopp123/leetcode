#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <limits.h>
using namespace std;

/**用bfs搜索方法
class Solution {
    public:
    bool canJump(vector<int>& nums) {
        queue<int> que;
        que.push(0);
        int vis[nums.size()];
        for (int i = 0; i < (int)nums.size(); i++) {
            vis[i] = INT_MAX;
        }
        vis[0] = 0;

        while (!que.empty()) {
            int index = que.front();
            que.pop();
            if (index == (int)nums.size() - 1) {
                return true;
            }
            int step = nums[index];
            for (int i = 1; i <= step; i++) {
                if (index + i < (int)nums.size()) {
                    int next = index + i;
                    if (vis[index] + 1 < vis[next]) {
                        vis[next] = vis[index] + 1;
                        que.push(next);
                    }
                }
            }
        }
        return false;
    }

};
*/
/*dp
 * 自底向上
 *
class Solution {
    public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        bool vis[len];
        memset(vis, false, sizeof(vis));
        vis[len - 1] = true;
        for (int i = len - 2; i >= 0; i--) {
            int step = min(i + nums[i], len - 1);
            for (int j = i + 1; j <= step; j++) {
                if (vis[j]) {
                    vis[i] = true;
                    break;
                }
            }
        }

        return vis[0];
    }
};
*/
class Solution {
    public:
    bool canJump(vector<int>& nums) {
        int len = (int)nums.size();
        int lastPosition = len - 1;
        for (int i = len - 2; i >= 0; i--) {
            if (i + nums[i] >= lastPosition) {
                lastPosition = i;
            }
        }

        return lastPosition == 0;
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
        cout << solution->canJump(nums) << endl;
    }

    return 0;
}
