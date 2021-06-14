# leetcode 142 Linked List Cycle

- walker-runner 방법의 응용
- 내 머리로 이걸 생각해낼 수 있을까 의문이 든다.



## 코드

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return None
        
        walker = head
        runner = head
        
        # 만나는 지점 찾기
        while runner is not None:
            runner = runner.next
            if runner is None:
                return None
            walker = walker.next
            runner = runner.next
            
            # 둘다 none에서 만나는 것(?)을 방지
            if runner is None:
                return None
            
            if walker == runner:
                break
        
        # 시작점부터 사이클이 시작되는 곳까지의 거리를 A
        # 사이클의 길이를 B
        # walker와 runner가 만난 지점과 루프의 시작까지의 거리를 X라고 했을 때 
        # walker의 위치는 루프를 한 바퀴 돌기 전에 runner를 만났을 것이므로 A+X
        # runner의 위치는 A + X + n*B가 된다(n은 루프를 돈 횟수)
        # runner = walker *2 이므로 방정식을 풀면 A+X = n*B가 된다.
        # 그러니까 X의 위치에서 A만큼 밀면 루프의 시작점을 알 수 있게 된다.
        another_walker = head
        
        while True:
            if another_walker != walker:
                another_walker = another_walker.next
                walker = walker.next
            else:
                return walker
```



