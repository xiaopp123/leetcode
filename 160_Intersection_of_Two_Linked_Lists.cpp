#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*1、哈希法，时间O(m+n), 空间O(m + n)
 * 2、两点法
 *    核心问题就是：交点往后的长度是A，B共有的，所以不知道A，B走多少步会到交点
 *    所以分别求A，B的长度，另长度较长的节点先走，走到与短的长度相同的位置，然后两个节点就分别一次一步，直到相交
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        int lenA = 0, lenB = 0;
        while (pA) {
            pA = pA->next;
            lenA++;
        }
        while (pB) {
            pB = pB->next;
            lenB++;
        }
        pA = headA;
        pB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                pA = pA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; i++) {
                pB = pB->next;
            }
        }
        while (pA && pB) {
            if (pA == pB) {
                return pA;
            }
            pA = pA->next;
            pB = pB->next;
        }

        return NULL;
    }
};

int main() {

    return 0;
}
