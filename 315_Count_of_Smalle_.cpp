#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            int counter = 0;
            for (int j = i + 1; j < (int)nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    counter++;
                }
            }
            res.push_back(counter);
        }

        return res;
    }
};

int main() {
    return 0;
}



