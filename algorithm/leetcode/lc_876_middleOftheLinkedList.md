# leetcode 876 Middle of LInkded  List

- 한 번 순회하면서 리스트의 사이즈를 알아낸 후에 size // 2만큼 순회를 반복하면 딱 중간노드가 나옴
- 워커 러너 테크닉 사용
  - 워커: 한 번에 한 칸씩
  - 러너: 한 번에 두 칸씩
  - 러너가 끝나면 워커는 중간에 와있음



## 순회  두 번 하는 코드

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        # 리스트의 길이를 알아야하고
        size = 0
        node = head
        while node:
            size += 1
            node = node.next
        
        middle = size // 2  # 이것이 반복횟수가 된다.
        cur = head
        for _ in range(middle):
            cur = cur.next        
            
        return cur
```



## 워커 러너 테크닉

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        # 워커-러너 테크닉 사용
        walker = head
        runner = head
        
        while runner != None:
            runner = runner.next
            if runner is None:
                break
            walker = walker.next
            runner = runner.next
        
        
        return walker
```



