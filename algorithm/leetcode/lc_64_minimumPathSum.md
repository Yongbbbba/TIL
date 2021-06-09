# leetcode minimum Path Sum

- DP: Bottom-up
- f(m, n) = min(f(m-1, n), f(m, n-1))



## 코드

```python
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        sumList = [[0] * n for _ in range(m)]
        sumList[0][0] = grid[0][0]
        
        for j in range(1, n):
            sumList[0][j] = grid[0][j] + sumList[0][j-1]
        for i in range(1, m):
            sumList[i][0] = grid[i][0] + sumList[i-1][0]
        
        for i in range(1, m):
            for j in range(1, n):
                sumList[i][j] = min(sumList[i-1][j], sumList[i][j-1]) + grid[i][j]
                
        return sumList[m-1][n-1]
```

