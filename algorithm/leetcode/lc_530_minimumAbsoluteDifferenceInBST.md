# leetcode 530 minimum Absolute Difference in BST

- 최대 노드 3개를 가지는 서브트리에서 각 노드의 차이 중 가장 작은 값을 구하다보면 전체 트리에서 가장 작은 차이를 가지는 노드를 발견할 수 있지 않을까 싶었는데 아니었다.



## 틀린 코드:

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    result = 100001
    def getMinimumDifference(self, root: TreeNode) -> int:
        # 노드의 개수가 3개인 서브트리 안의 숫자들의 차이가 가장 작지 않을까?
        
        def f(start, left, right):
            if start is None or (left == None and right == None):
                return
            elif left and right:
                temp = min(abs(start.val - left.val), abs(start.val - right.val), abs(left.val - right.val))
                if self.result > temp:
                    self.result = temp
                f(left, left.left, left.right)
                f(right, right.left, right.right)
            elif left:
                temp = abs(start.val - left.val)
                if self.result > temp:
                    self.result = temp
                f(left, left.left, left.right)
            else:
                temp = abs(start.val - right.val)
                if self.result > temp:
                    self.result = temp
                f(right, right.left, right.right)

        
        left  = root.left
        right = root.right
        f(root, left, right)

        return self.result
        
```



## 승지니어님 풀이

- 이진검색트리의 경우 inorder 순회하면서 리스트를 만들면 오름차순 정렬이 된다. 나는 이렇게 배열을 만든 후에 이중 순회하면서 차이가 가장 작은 값을 찾아 봤다.

``` python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def getMinimumDifference(self, root: TreeNode) -> int:
        result = 100001
        arr = []
        def inorder(start):
            if start is None:
                return
            inorder(start.left)
            arr.append(start.val)
            inorder(start.right)
        
        inorder(root)
        n = len(arr)
        for i in range(n-1):
            for j in range(i+1, n):
                temp = abs(arr[i] - arr[j])
                if temp < result:
                    result = temp
        return result
```



흠 .. 

이중 순회를 할 필요가 없다.

만약 arr=  [2,5,6,10, 12, 25]가 있을 때, 2,5를 비교하고 2와 5의 다음 숫자를 비교해봤자 어차피 오름차순 정렬이니까 그 뒤는 볼 것도 없기 때문이다. 그러니까 (2,5), (5,6), (6,10) .. 이런 식으로만 비교하면 inorder 순회하면서 동시에 min 체크 가능하다.

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    result = 100001
    isChecked = False
    prevNode = None

    
    def getMinimumDifference(self, root: TreeNode) -> int:
        # 함수 시작
        def inorder(node):
            if node is None:
                return
        
            inorder(node.left)

            if not self.isChecked:
                self.isChecked = True
            else:
                self.result = min(self.result, abs(self.prevNode.val - node.val))
            self.prevNode = node

            inorder(node.right)
        
        # 함수 끝
        inorder(root)

        return self.result
```

