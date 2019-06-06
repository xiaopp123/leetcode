#include "heads.h"
using namespace std;

class Solution {
    public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> nums_string;
        for (int i = 0; i < (int)nums.size(); i++) {
            nums_string.push_back(to_string(nums[i]));
        }
        sort(nums_string.begin(), nums_string.end(), cmp);
        string res = "";
        for (int i = 0; i < (int)nums_string.size(); i++) {
            res += nums_string[i];
        }
        if (res[0] == '0') {
            return "0";
        } else {
            return res;
        }
    }
};

int main() {
    return 0;
}
