#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
		map<int, int> m;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			m[nums[i]] = i;
		}
		int num;
		for (int i = 0; i < len; i++) {
			num = target - nums[i];
			if (m.count(num) > 0 && m[num] != i) {
				res.push_back(i);
				res.push_back(m[num]);
				break;
			}
			
		}

		return res;
    }
};

int main() {
    Solution solution = Solution();
    int n, target;
    vector<int> nums;
    int num;
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
       cin >> num;
       nums.push_back(num);
    }
    vector<int> res = solution.twoSum(nums, target);
	for (int i = 0; i < (int) res.size(); i++) {
	    cout << res[i] << endl;
	}
    
    return 0;
}
