# leetcode 589 N-ary Preorder Traversal

- 재귀로 풀면 쉽다. 재귀를 안쓰고 반복문으로도 할 수 있나?



## 재귀

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    
    def preorder(self, root: 'Node') -> List[int]:
        result = []
        if root is None:
            return []
        
        def f(node):
            if node is None:
                return
            
            result.append(node.val)

            for c in node.children:
                f(c)
            
        f(root)
            
            
        return result
```



## 반복문 이용: 스택을 사용해야함

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    
    def preorder(self, root: 'Node') -> List[int]:
        
        result = []
        s = []
        s.append(root)
        
        if root is None:
            return result
        
        while s:
            node = s.pop()
            result.append(node.val)
            for i in range(len(node.children)-1, -1, -1):
                s.append(node.children[i])
    
            
        return result
```

