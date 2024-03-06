/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0)
            return head;
        ListNode *temp = head;
        ListNode *p = head;
        ListNode *q;
        int size = 1;   //计算出链表总长度
        while(temp->next)
        {
            temp = temp->next;
            size++;
        }
        temp->next = head;//形成环

        int num = size - (k % size);
        if(num == 0) return head;
        for(int i = 1; i < num; ++i)
        {
            p = p->next;
        }
        q = p->next;
        p->next = nullptr; //断开环
        return q;
    }
};




class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head; // 处理空链表或不需要旋转的情况
        
        ListNode *temp = head;
        int size = 1; // 初始化为 1，因为已经有一个节点（头节点）
        while(temp->next) {
            temp = temp->next;
            size++;
        }
        temp->next = head; // 将链表首尾相连，形成环

        k = k % size; // 如果 k 大于链表长度，取模得到实际需要旋转的次数
        if (k == 0) return head; // 如果 k 是链表长度的整数倍，不需要旋转
        
        int stepsToNewHead = size - k;
        ListNode *newTail = head;
        for (int i = 1; i < stepsToNewHead; ++i) {
            newTail = newTail->next;
        }
        ListNode *newHead = newTail->next;
        newTail->next = nullptr; // 断开环
        
        return newHead;
    }
};
