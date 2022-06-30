# leetcode 20 Valid Parentheses

- 스택 이용. 오늘 머리가 잘 안돌아가네.. 



## 코드

```python
class Solution:
    def isValid(self, s: str) -> bool:
        # () -> first, [] -> second, {} -> third
        stack = []
        
        for c in s:
            if c == '[' or c == '(' or c == '{':
                stack.append(c)
            elif len(stack) == 0:
                return False
            elif c == ']':
                if stack[-1] != '[':
                    return False
                stack.pop()
            elif c == '}':
                if stack[-1] != '{':
                    return False
                stack.pop()
            elif c == ')':
                if stack[-1] != '(':
                    return False
                stack.pop()
                    
        if stack:
            return False
        return True
```



## 1년 뒤 풀이 : 2022-06-03

- 이런 쉬운 문제도 이렇게 오답을 많이 제출하는구나.. 

```c++
class Solution {
public:
    bool isValid(string s) {
        vector<char> arr{ '(','[', '{', ')', ']', '}' };
        stack<char> st;

        for (auto& c : s)
        {
            if (c == arr[0] || c == arr[1] | c == arr[2])
            {
                st.emplace(c);
            }
            else
            {
                 if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if (top == arr[0] && c != arr[3])
                    return false;
                if (top == arr[1] && c != arr[4])
                    return false;
                if (top == arr[2] && c != arr[5])
                    return false;
            }
        }
        
        if (!st.empty())
            return false;

        return true;
    }
};
```

