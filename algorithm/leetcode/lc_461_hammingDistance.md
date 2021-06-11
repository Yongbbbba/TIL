# leetcode  461 Hamming Distance

- 비트값이 다른 경우를 세는 것이기 때문에 xor 연산을 이용



## 코드

```python
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        result = 0
        xor = x ^ y
        
        for i in range(32):
            result +=(xor >> i) & 1
        
        return result
```

