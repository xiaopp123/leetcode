#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            bucket[it->second].push_back(it->first);
        }
        vector<int> res;
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < (int)bucket[i].size(); j++) {
                res.push_back(bucket[i][j]);
                if ((int)res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

/**
 * https://leetcode.com/problems/top-k-frequent-elements/
 * 方案二：桶排序
 * 首先建立数字和频数的映射表
 * 然后根据频数进行桶排序，频数对应的是一个数组，因为同一频数的可能有多个数
 * 根据频数桶从大到小取数，如果个数等于k，直接返回，否则最后返回
 */
class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        int n = nums.size();
        vector<vector<int> > bucket(n + 1);
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            m[nums[i]]++;
        }
        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            bucket[it->second].push_back(it->first);
        }
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < (int)bucket[i].size(); j++) {
                res.push_back(bucket[i][j]);
                if ((int)res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
/**
 * 方案一、堆
 * 首先建立数与频数的映射表
 * 按频数从大到小排序，取前k个
 * 用优先队列实现
 */
/*
class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        priority_queue<pair<int, int> > que;
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            m[nums[i]]++;
        }
        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            que.push({it->second, it->first});
        }
        for (int i = 0; i < k; i++) {
            res.push_back(que.top().second);
            que.pop();
        }

        return res;
    }
};
*/

int main() {
    return 0;
}
