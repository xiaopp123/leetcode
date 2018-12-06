#include <cstdio>
#include <algorithm>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/* 快指针与慢指针
 * 它们相交于z点，从头开始到环的起点的长度 等于 交点z到环的起点长度
 * 所以在求出交点之后，设置两个指针，一个在头部，一个在z处，一次一步，相遇时即为环的起点
 * 参考博客：https://www.cnblogs.com/hiddenfox/p/3408931.html
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                break;
            }
        }
        if (fast->next == NULL || fast->next->next == NULL) {
            return NULL;
        }

        ListNode *temp = head;
        while (temp != fast) {
            temp = temp->next;
            fast = fast->next;
        }

        return temp;

    }
};

int main() {
    return 0;
}
