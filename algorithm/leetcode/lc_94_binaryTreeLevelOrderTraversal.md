# leetcode 94 Binary Tree Level Order  Traveral 

- 재귀 또는 반복문으로 구현 가능



## 재귀 

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        result = []
        
        def f(node):
            if node is None:
                return
            
            f(node.left)
            result.append(node.val)
            f(node.right)
            
        f(root)
        return result
```

