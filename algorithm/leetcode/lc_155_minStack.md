# leetcode 155 min stack

- getMin()을 해결하지 못하고 답안을 보았음
- min값을 기록하는 stack을 하나 더 둠으로써 space complexity를 조금 희생함

## 코드

```c++
class MinStack {
public:
    stack<int> numSt;
    stack<int> minSt;
    
    MinStack() {
            
    }
    
    void push(int val) {
        numSt.push(val);
        if (!minSt.empty())
        {
            if (minSt.top() <= val)
            {
                minSt.push(minSt.top());
            }
            else
            {
                minSt.push(val);
            }
        }
        else
        {
            minSt.push(val);
        }
    }
    
    void pop() {
        minSt.pop();
        numSt.pop();
    }
    
    int top() {
        return numSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

