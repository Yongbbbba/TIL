# leetcode 107 Binary Tree Level Order  Traveral 2

- 각 레벨을 key로 하는 딕셔너리를 만들어서 활용하였다.



## 코드

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        
        dic = {}
        
        def f(node, level):
            if node is None:
                return
            
            if dic.get(level) is not None:
                dic.get(level).append(node.val)
            else:
                dic[level] = [node.val]
            
            f(node.left, level+1)
            f(node.right, level+1)
                
        f(root, 0)
        level = max(list(dic.keys()))
        result = []
        while level >= 0:
            result.append(dic[level])
            level -= 1
            
        return result
```

