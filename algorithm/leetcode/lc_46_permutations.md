# leetcode 46 permutations

- 푸는 법은 알겠는데 내가 class를 잘 못쓰는건지 뭔지.. 리트코드의 템플릿에서 구현이 제대로 되지 않았다. 그래서 오래 걸렸다.



## 코드

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        
        def f(temp):
            if len(temp) == len(nums):
                result.append(temp)
                return 
            else:
                for num in nums:
                    if num in temp:
                        continue
                    f(temp+[num])
                    
        f([])
        return result
```

