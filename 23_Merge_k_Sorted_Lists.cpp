#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 采用归并的方法，划分成两份进行合并
 * 写的代码太丑了
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listNum = lists.size();
        //第一 要判断输入集合是否为空
        if (listNum == 0) {
            return NULL;
        }
        return merge2Lists(lists, 0, listNum - 1);
    }
    ListNode* merge2Lists(vector<ListNode*>& lists, int start, int end) {
        //只有一个元素时就返回
        if (start == end) {
            //if (lists[start]) {
            return lists[start];
            //}
            //return NULL;
        }
        //第二个 确定中间元素的位置,调试好久=_=
        int mid = (end - start)/2 + start;

        ListNode *leftList = merge2Lists(lists, start, mid);
        ListNode *rightList = merge2Lists(lists, mid + 1, end);

        //合并
        ListNode* res = new ListNode(-1);
        ListNode* returnRes = res;
        while (leftList && rightList) {
            if (leftList->val < rightList->val) {
                res->next = leftList;
                leftList = leftList->next;
            } else {
                res->next = rightList;
                rightList = rightList->next;
            }
            res = res->next;
        }
        while (leftList) {
            res->next = leftList;
            leftList = leftList->next;
            res = res->next;
        }
        while (rightList) {
            res->next = rightList;
            rightList = rightList->next;
            res = res->next;
        }

        return returnRes->next;
    }
};

int main() {
    Solution* solution = new Solution();
    vector<ListNode*> lists;
    ListNode* l0 = new ListNode(-1);
    lists.push_back(l0->next);

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    lists.push_back(l1);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    lists.push_back(l2->next->next->next);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    lists.push_back(l3);

    ListNode* res = solution->mergeKLists(lists);
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }




    return 0;
}
