#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int> > res;
    private:
        void dfs(int s, int n, int k, vector<int> item, bool vis[]) {
            int len = (int)item.size();
            if (len == k) {
                res.push_back(item);
                return;
            }
            int t = k - len;
            for (int i = s; i <= n; i++) {
                if (t > 0 && vis[i] == false) {
                    item.push_back(i);
                    t--;
                    vis[i] = true;
                    dfs(i + 1, n, k, item, vis);
                    t++;
                    vis[i] = false;
                    item.pop_back();
                }
            }
        }
    public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> item;
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        dfs(1, n, k, item, vis);
        return res;
    }
};

int main() {
    return 0;
}
