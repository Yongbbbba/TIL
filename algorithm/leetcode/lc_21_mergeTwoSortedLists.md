# leetcode 21 Merge Two Sorted Lists

- 로직 자체는 매우 간단했는데, 파이썬에서 포인터를 안쓰고 해보니까 노드가 연결되는 과정이 이해가 가지 않아서 구현에 시간을 너무 쓰게 되었다. result node의 next node가 어떻게 바뀌는건지 이해가 안가더라.. 



## 코드

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur = None
        head = None
        
        while l1 != None or l2 != None:
            # l1만 선택되는 경우
            if l2 == None or (l1 != None and l1.val < l2.val):
                # 첫 번째 선택인 경우
                if head == None:
                    head = l1  # 현재 l1의 노드 주소가 복사되는 것이라고 이해하자. 값만 복사되는 것이 아님
                    cur = l1
                    l1 = l1.next
                else:
                    cur.next = l1
                    cur = cur.next
                    l1 = l1.next
            # l2만 선택되는 경우
            elif l1 == None or (l2 != None and l1.val >= l2.val):
                if head == None:
                    head = l2
                    cur = l2
                    l2 = l2.next
                else:
                    cur.next = l2
                    cur = cur.next
                    l2 = l2.next
                        
        return head
        
            
   
```

