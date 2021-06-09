# leetcode 70 climbing Stairs

- dp 기초 문제 
- 피보나치와 거의 동일
- bottom-up 방식 사용 

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        # bottom-up 방식
        dp = [0, 1, 2]
        
        if n == 1 or n == 2:
            return dp[n]
        
        for i in range(3, n+1):
            new = dp[i-2] + dp[i-1]
            dp.append(new)
        
        return dp[n]
```

