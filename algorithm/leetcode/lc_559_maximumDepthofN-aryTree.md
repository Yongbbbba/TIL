# leetcode 559 Maximum Depth of N-ary Tree

- DFS 방식의 탐색. 재귀를 사용
- 꼼꼼하게 코드를 짜자... 로직을 분명하게 생각해보고



## 코드

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    result = 0
    def maxDepth(self, root: 'Node') -> int:
        # 재귀로 풀어보기
        # DFS의 방식
        if root is None:
            return 0
        
        def f(lev, node):
            if node is None:
                return
            
            if lev > self.result:
                self.result = lev
            
            for child in node.children:
                f(lev+1, child)
        
        f(1, root)
        return self.result
                
```

