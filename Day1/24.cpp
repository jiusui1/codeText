/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *curr = dummyHead;
        while(curr->next != nullptr && curr->next->next != nullptr)
        {
            ListNode *temp = curr->next;
            ListNode *temp2 = curr->next->next->next;

            curr->next = curr->next->next;
            curr->next->next = temp;
            curr->next->next->next = temp2;

            curr = curr->next->next;
        }
        return dummyHead->next;
    }
};