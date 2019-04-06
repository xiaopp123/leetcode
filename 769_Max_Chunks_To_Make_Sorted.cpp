#include "heads.h"
using namespace std;

class Solution {
    public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = (int)arr.size();
        if (n == 0) {
            return 0;
        }
        int ans = 0;
        int maxn = arr[0];
        for (int i = 0; i < n; i++) {
            maxn = max(maxn, arr[i]);
            if (maxn == i) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    Solution* solution = new Solution();
    cout << solution->maxChunksToSorted(arr) << endl;
    return 0;
}
