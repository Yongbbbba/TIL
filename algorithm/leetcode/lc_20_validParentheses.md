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

