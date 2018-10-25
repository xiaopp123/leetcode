#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/container-with-most-water/description/
 * 1、暴力，复杂度n方
 * 2、两个点，一个点在开始的地方，另一个点在结束的地方，此时有一个面积，然后移动这两个点，怎么移动？
 * 当移动时，可能是矩形的长变小了，为了尽量使面积变大，所以要移动这个位置较小的那一个，这样才能保证移动后的面积有可能会变大
 */
class Solution {
    public:
    int maxArea(vector<int>& height) {
            int len = height.size();
            int l = 0, r = len - 1;
            int maxNum = 0;
            while (l < r) {
                maxNum = max(maxNum, min(height[l], height[r]) * (r - l));
                if (height[l] < height[r]) {
                    l++;
                } else {
                    r--;
                }
            }

            return maxNum;
        }
};

int main() {
    Solution *solution = new Solution();
    vector<int> height;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        height.push_back(t);
    }

    cout << solution->maxArea(height);

    return 0;
}
