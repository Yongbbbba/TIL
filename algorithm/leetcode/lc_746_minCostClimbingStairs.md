# leetcode 746 Min Cost Climbing Stairs

- dp 문제
- F(n) = Min(F(n-2)+cost(n-2), F(n-1)+cost(n-1))



## 코드

```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        minCost = [0, 0, min(cost[0], cost[1])]
        
        n = len(cost)
        if n == 2:
            return minCost[2]
        
        for i in range(3, n+1):
            new = min(cost[i-2] + minCost[i-2], cost[i-1] + minCost[i-1])
            minCost.append(new)
        return minCost[n]   
```



