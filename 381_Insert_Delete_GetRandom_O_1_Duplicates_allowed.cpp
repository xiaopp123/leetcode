#include "heads.h"
using namespace std;

class RandomizedCollection {
    private:
        vector<int> nums;
        map<int, priority_queue<int>> mp;
    public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        mp[val].push(nums.size() - 1);

        return nums.size() == 1;
    }
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (mp[val].empty()) {
            return false;
        }
        //取出要删除的元素
        int val_id = mp[val].top();
        mp[val].pop();

        //如果要删除的元素不是最后一个元素,则与最后一个元素交换
        if (val_id != (int)nums.size() - 1) {
            int last = nums.back();
            mp[last].pop();
            mp[last].push(val_id);
            nums[val_id] = last;
        }

        nums.pop_back();

        return true;
    }
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
        }
};


int main() {
    return 0;
}
