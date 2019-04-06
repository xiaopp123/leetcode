#include "heads.h"
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int> > g(numCourses, vector<int>(numCourses, 0));
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            pair<int, int> t = prerequisites[i];
            indegree[t.first]++;
            g[t.second][t.first] = 1;
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }
        if (que.empty()) {
            return false;
        }

        while (!que.empty()) {
            int t = que.front();
            que.pop();
            for (int i = 0; i < numCourses; i++) {
                if (g[t][i]) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        que.push(i);
                        g[t][i] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] > 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    vector<pair<int, int> > classes;
    cin >> n;
    for (int i = 0; i < n; i++) {
        pair<int, int> classe;
        cin >> classe.first >> classe.second;
        classes.push_back(classe);
    }
    Solution *solution = new Solution();
    cout << solution->canFinish(n, classes) << endl;

    return 0;
}
