class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    MyLinkedList()
    {

    }

    int get(int index)
    {

    }

    void addAtHead(int val)
    {
    }

    void addAtTail(int val)
    {
    }

    void addAtIndex(int index, int val)
    {
    }

    void deleteAtIndex(int index)
    {
    }
private:
    ListNode *head;
    ListNode *tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */