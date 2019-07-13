#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 == 0 || n2 == 0) {
            return res;
        }
        map<int, int> mp;
        for (int i = 0; i < n1; i++) {
            mp[nums1[i]]++;
        }
        for (int i = 0; i < n2; i++) {
            if (mp.count(nums2[i]) > 0 && mp[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                mp[nums2[i]]--;
                if (mp[nums2[i]] == 0) {
                    mp.erase(nums2[i]);
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
