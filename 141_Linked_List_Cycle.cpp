#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 采用hash的方法，如果出现两个一样的就是有环的
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        map<ListNode, int> mp;
        while (head) {
            if (mp.count(*head) > 0) {
                return true;
            } else {
                mp[*head] = 1;
            }
        }
    }
};
*/
//双指针法，一个快的一个慢的
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        ListNode *slow = head, *fast = head->next;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    return 0;
}
