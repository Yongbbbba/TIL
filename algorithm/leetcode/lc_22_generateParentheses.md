# leetcode 22 Generate Parenttheses

- 백트랙킹 사용



## 코드

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        def f(n,  left, right, temp):
            # n은 만들어야하는 괄호의 갯수, left 왼쪽 괄호의 수, right는 오른쪽 괄호의 수, temp는 현재까지 만든 string

            if n == left and n == right:
                result.append(temp)
                return

            # 늘 두 가지의 선택, '(', ')'를 할 수 있음
            # ')'는 left > right이어야지 추가 가능
            # '('는 left가 3보다 작으면 추가 가능

            if left < n:
                f(n, left+1, right, temp+'(')
            if left > right:
                f(n, left, right+1, temp+')')
                
        f(n, 0, 0, '')
        return result
        
```

