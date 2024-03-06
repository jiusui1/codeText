/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;//快指针
        ListNode *slow = head;//慢指针
        while(fast != nullptr and fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                ListNode *p = fast;
                ListNode *q = head;
                while(p != q)
                {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }

        }
        return nullptr;
    }
};