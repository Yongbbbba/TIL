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



## 1년뒤 풀이 : 2022-06-12

### O(n*m) 풀이

- kmp 알고리즘 공부했는데 이해 안돼서 이번에 패스.. 

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        // O(n*m)으로 풀이 
        int needleLen = needle.length();
        int haystackLen = haystack.length();
        int result = -1;
        for (int i = 0; i < haystackLen; i++)
        {
            for (int j = 0; j < needleLen; j++)
            {
                if (needle[j] == haystack[i + j])
                {
                    if (j == needleLen - 1)
                    {
                        result = i;
                        return result;
                    }
                    else
                    {
                        continue;
                    }
               }
                else
                {
                    break;
                }
            }
        }
        return result;
    }
};
```

