# leetcode 169 Majority Element

- 나는 그냥 정렬 후 완전 탐색 사용
- 하지만 문제에서 추가 공간을 사용하지 않고 선형의 시간복잡도로 문제를 해결하라는 문구가 있어서 다르게 풀이해야함.



## 완전 탐색 코드

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        arr = sorted(nums)
        
        majority = n / 2
        temp = 0
        now = arr[0]
        for num in arr:
            if num == now:
                temp += 1
            else:
                if majority < temp:
                    break
                temp = 1
                now = num
        return now
        
        
```



## 과반수 찾는 알고리즘 사용..

내 머리로는 생각 못할 알고리즘

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        result = None
        cnt = 0
        for num in nums:
            if cnt==0:
                result = num
                cnt += 1  # cnt = 1
            elif num == result:
                cnt += 1
            else:
                cnt -= 1
                
        return result
```

