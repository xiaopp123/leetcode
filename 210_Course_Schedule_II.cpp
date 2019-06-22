#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        vector<int> in(numCourses, 0);
        for (int i = 0; i < (int)prerequisites.size(); i++) {
            in[prerequisites[i][0]]++;
            graph[ prerequisites[i][1] ].push_back(prerequisites[i][0]);
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                que.push(i);
            }
        }
        vector<int> res;
        while (!que.empty()) {
            int top = que.front();
            que.pop();
            res.push_back(top);
            for (int i = 0; i < (int)graph[top].size(); i++) {
                in[graph[top][i]]--;
                if (in[graph[top][i]] == 0) {
                    que.push(graph[top][i]);
                }
            }
        }
        if ((int)res.size() == numCourses) {
            return res;
        } else {
            return vector<int>{};
        }

    }
};

int main() {

    return 0;
}
