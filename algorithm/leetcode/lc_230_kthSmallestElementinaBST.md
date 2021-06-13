# leetcode 230 Kth Smallest Element in a BST

- inorder 순회를 하면 오름차순으로 정렬이 되는 점을 이용한다. 
- value를 리스트에 넣은 후 k번째로 작은 숫자를 인덱스를 통해 찾아낸다. 
- 시간 복잡도: O(n), 공간 복잡도: O(n)



## 코드

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        # 이진탐색트리의 경우에는 inorder 순회를 하면 오름차순으로 정렬이 된다.
        result = []
        
        def inorder(node):
            if node is None:
                return
            
            inorder(node.left)
            result.append(node.val)
            inorder(node.right)
        
        inorder(root)  # 오름차순으로 정렬이 된다.
        
        return result[k-1]
```

