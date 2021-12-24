// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> s1, s2;
    int sz = 0;

    MyQueue() {
        sz = 0;
    }
    
    void push(int x) {
        sz++;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        sz--;
        if (s1.empty()) return -1;
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        if(s1.empty()) return -1;
        return s1.top();
    }
    
    bool empty() {
        return (sz == 0);
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

