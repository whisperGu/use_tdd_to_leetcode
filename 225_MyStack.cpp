使用队列实现栈的下列操作：


	push(x) -- 元素 x 入栈
	pop() -- 移除栈顶元素
	top() -- 获取栈顶元素
	empty() -- 返回栈是否为空

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (q1.empty())
        {
            q1.push(x);
            while(!q2.empty())
            {
                int val = q2.front();
                q2.pop();
                q1.push(val);
            }
        }
        else
        {
            q2.push(x);
            while(!q1.empty())
            {
                int val = q1.front();
                q1.pop();
                q2.push(val);
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top_val = 0;
        if (q1.empty())
        {
            top_val = q2.front();
            q2.pop();
        }
        else
        {
            top_val = q1.front();
            q1.pop();
        }
        return top_val;
    }
    
    /** Get the top element. */
    int top() {
        int top_val = 0;
        if (q1.empty())
        {
            top_val = q2.front();
        }
        else
        {
            top_val = q1.front();
        }
        return top_val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
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
