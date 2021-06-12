# leetcode 1 Two Sum

- 리트코드의 역사적인 첫 문제
- O(n^2) 보다 작은 시간복잡도로 문제 풀이를 할 수 있는가? -공간 복잡도의 희생이 발생하더라도 = trade off 가 존재한다.



## 코드: 이중 순회

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n-1):
            for j in range(i+1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
```



## 코드: 해쉬테이블 사용

먼저 한 번 순회하면서 해쉬테이블을 만들고, a + b = target을 만족하는 pair가 있는지 확인하면 O(n) + O(n)으로 확인 가능해진다.



```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        dic = {}
        for i, num in enumerate(nums):
            dic[num] = i
        
        for i in range(n):
            if dic.get(target-nums[i]) and dic.get(target-nums[i]) != i:
                return [dic[target-nums[i]], i]
```

아 생각해보니 처음 해쉬테이블을 만들 때 동시에 pair check가 가능하다.

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i, num in enumerate(nums):
            if dic.get(target-num) is not None:
                return [dic.get(target-num), i]
            else:
                dic[num] = i
```

