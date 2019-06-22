#include "heads.h"
using namespace std;

class MedianFinder {
    public:
    vector<int> nums;
    /** initialize your data structure here. */
    MedianFinder() {
        nums.clear();
    }
    void addNum(int num) {
        if (nums.empty()) {
            nums.push_back(num);
        }
        int idx = lower_bound(nums.begin(), nums.end(), num) - nums.begin();
        nums.insert(nums.begin() + idx, num);
    }

    double findMedian() {
        int n = nums.size();
        if (n % 2) {
            return nums[n / 2];
        } else {
            return (nums[n / 2] + nums[n / 2 + 1]) / 2;
        }
    }
};

/**
 *  * Your MedianFinder object will be instantiated and called as such:
 *   * MedianFinder* obj = new MedianFinder();
 *    * obj->addNum(num);
 *     * double param_2 = obj->findMedian();
 *      */

int main() {
    return 0;
}
