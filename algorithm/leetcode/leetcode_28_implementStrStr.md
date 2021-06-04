# leetcode 28 Implement strStr()

- 왜 쉽게 안풀리지 이게 .. python이면 find 써서 쉽게 구하겠지만 메소드 안쓰고 구해보자

  ```python
  class Solution(object):
      def strStr(self, haystack, needle):
          if len(needle) == 0:
              return 0
          return haystack.find(needle)
  ```

  

## 정답 코드

```python
class Solution(object):
    def strStr(self, haystack, needle):
        if len(needle) == 0:
            return 0
        if len(needle) > len(haystack):
            return -1
        
        for idx in range(len(haystack) - len(needle) + 1):
            nIdx = 0
            while nIdx < len(needle):
                if haystack[idx + nIdx] == needle[nIdx]:
                    nIdx+=1
                    continue
                else:
                    break
            if nIdx == len(needle):
                return idx
        return -1
```

