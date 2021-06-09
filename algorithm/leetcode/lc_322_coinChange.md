# leetcode 322 Coin  Change

- DP



## 코드

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins = sorted(coins)
        # k는 동전의 개수 -> O(k*N)의 시간 복잡도를 가짐
        dp = [-1] * (amount+1)
        dp[0] = 0
        # f(n) = min(f(n-x1), f(n-x2), f(n-x3)) + 1
        for idx in range(amount+1):
            if dp[idx] != -1:
                continue
            if coins[0] > idx:
                continue
            temp = []
            for coin in coins:
                if coin > idx:
                    continue
                if dp[idx-coin] != -1:
                    temp.append(dp[idx-coin])
            if len(temp) == 0:
                continue
            new = min(temp) + 1
            dp[idx] = new
        
        
        return dp[amount]
 
```

