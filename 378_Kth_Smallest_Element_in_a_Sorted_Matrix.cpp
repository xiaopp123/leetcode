#include "heads.h"
using namespace std;

/*
class Solution {
    public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) {
            return 0;
        }
        vector<int> column;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            column.push_back(matrix[i][0]);
        }
        int cl = lower_bound(column.begin(), column.end(), k) - column.begin();
        if (column[cl] != k) {
            cl--;
        }
        int rl = lower_bound(matrix[cl].begin(), matrix[cl].end(), k) - matrix[cl].begin();
        if (rl) {

        }
    }
};
*/
class Solution {
    public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) {
            return 0;
        }
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = matrix[n][0];
        int right = matrix[n][m - 1];
        while (left < right) {
            int mid = (left + right) / 2;
            cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), k) - matrix[i].begin();
            }
            if (cnt < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

/*
class Solution {
    public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) {
            return 0;
        }
        priority_queue<int> que;
        for (int i = 0; i < (int)matrix.size(); i++) {
            for (int j = 0; j < (int)matrix[0].size(); j++) {
                que.push(matrix[i][j]);
                if ((int)que.size() > k) {
                    que.pop();
                }
            }
        }
        return que.top();
    }
};
*/
/*
class Solution {
    public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) {
            return 0;
        }
        vector<int> nums;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nums.push_back(matrix[i][j]);
            }
        }
        sort(nums.begin(), nums.end());

        return nums[k];

    }
};
*/

int main() {
    return 0;
}
