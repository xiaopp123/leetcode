#include "heads.h"
using namespace std;

/**
 * 需要两个栈，一个是正常栈，另一个存放的是最下栈
 *
 */
class MinStack {
    private:
        stack<int> st;
        stack<int> min_st;
    public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        st.push(x);
        if (min_st.empty() || (!min_st.empty() && x <= min_st.top())) {
            min_st.push(x);
        }
    }

    void pop() {
        if (!st.empty()) {
            if (!min_st.empty() && st.top() == min_st.top()) {
                min_st.pop();
            }
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};

/**
 *  * Your MinStack object will be instantiated and called as such:
 *   * MinStack obj = new MinStack();
 *    * obj.push(x);
 *     * obj.pop();
 *      * int param_3 = obj.top();
 *       * int param_4 = obj.getMin();
 *        */

int main() {
    return 0;
}
