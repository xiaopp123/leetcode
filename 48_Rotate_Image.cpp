#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * https://leetcode.com/problems/rotate-image/description/
 * 矩阵旋转90度分两步处理：
 * 1、沿主对角线转置
 * 2、沿纵轴求对称
 */

class Solution {
    public:
    void rotate(vector<vector<int>>& matrix) {
        //转置
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //对称
        int mid = n / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mid; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }

    }
};
int main() {

    return 0;
}
