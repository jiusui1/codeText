class MyStack {
public:
    queue<int> que1;
    queue<int> que2;

    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size() - 1;
        while (size--)
        {
            // 将que1 导入que2，但要留下最后一个元素
            que2.push(que1.front());
            que1.pop();
        }
        int res = que1.front(); // 留下的最后一个元素就是要返回的值
        que1.pop(); 
        que1 = que2; // 交换两个队列
        while (que2.empty())
        {
            que2.pop();
        }
        
        return res;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */