# leetcode 141 LinkedList Cycle

- walker runner 사용
- walker는 한 칸씩 전진하고 runner는 두 칸씩  전진했을 때 runner가 null에 도달하면 false, 언젠가 두 칸이 만나면 true



## 코드

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None or head.next is None:
            return False
        
        ## walker: 한 칸씩 전진
        ## runner: 두 칸씩 전진
        ## 만약 사이클이 있다면 둘은 언젠가는 만남
        ## 사이클이 없다면 runner가 null에 닿음
        
        walker = head
        runner = head
        
        while runner is not None:
            runner = runner.next
            if runner is None:
                return False
            walker = walker.next
            runner = runner.next
            if runner == walker:
                return True
```

