#include <bits/stdc++.h>
class MyQueue
{
public:
    stack<int> S1;
    stack<int> S2;
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!S1.empty())
        {
            S2.push(S1.top());
            S1.pop();
        }
        S2.push(x);
        while (!S2.empty())
        {
            S1.push(S2.top());
            S2.pop();
        }
    }

    int pop()
    {
        int curr = S1.top();
        S1.pop();
        return curr;
    }

    int peek()
    {
        return S1.top();
    }

    bool empty()
    {
        return S1.empty();
    }
};
int main()
{
    MyQueue q;
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */