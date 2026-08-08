class MyQueue {
private:
    stack<int> s;
    stack<int> t;

public:
    MyQueue() {}
    
    void push(int x) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int y = s.top();
            s.pop();
            t.push(y);
        }
        s.push(x);
        for (int i = 0; i < n; ++i) {
            int y = t.top();
            t.pop();
            s.push(y);
        }
    }
    
    int pop() {
        int result = s.top();
        s.pop();
        return result;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
