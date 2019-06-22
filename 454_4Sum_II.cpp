#include "heads.h"
using namespace std;

class Solution {
    public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt[A[i] + B[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += cnt[-(C[i] + D[j])];
            }
        }

        return res;
    }
};

int main() {
}
