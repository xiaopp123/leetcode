#include "heads.h"
using namespace std;

class RandomizedSet {
    private:
        vector<int> nums;
        map<int, int> mp;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val) > 0) {
            return false;
        }
        nums.push_back(val);
        mp[val] = nums.size() - 1;

        return true;
    }
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.count(val) <= 0) {
            return false;
        }
        //调换最后一个和目标值,删除最后一个
        int last_v = nums.back();
        mp[last_v] = mp[val];
        nums[mp[val]] = last_v;
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {

    return 0;
}
