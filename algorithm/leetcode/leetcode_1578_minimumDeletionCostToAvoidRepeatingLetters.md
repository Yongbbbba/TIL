# leetcode 1578 Minimum Deletion Cost to Aovid Repeating Letters

- 그리디로 생각보다 쉽게 풀이함
- 다음 글자와 동일한 글자가 나올 때 비용이 가장 작은 것을 선택함



```python
class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        # 그리디 방법으로 풀이. 앞에서부터 순회하면서 일단 cost 가장 작은 것 제거
        result = 0
        n = len(s)
        for i in range(n-1):
            if s[i] == s[i+1]:
                if cost[i] < cost[i+1]:
                    result += cost[i]
                else:
                    result += cost[i+1]
                    cost[i+1] = cost[i]  #  cost[i+1]을 가지는 letter는 삭제된 것이니 이런 식으로 보정해줌
        return result
```

