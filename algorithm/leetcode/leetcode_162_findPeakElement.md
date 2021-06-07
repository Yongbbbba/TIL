# # leetcode 162 Find Peak Element

- O(N)으로 풀면 간단하지만 O(log N)의 시간복잡도로 답을 구하라는 문제의 요구사항이 있었다. 그래서 바이너리 서치를 사용해야한다.
- 배열의 원소를 가지고 그래프를 그려보면 문제의 답을 이해하기 쉬워진다.

##  코드

```python
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return 0
        
        left = 0
        right = len(nums) - 1
        
        while left < right:
            pivot = (left + right) // 2
            num = nums[pivot]
            
            if num < nums[pivot+1]:
                # peak는 pivot 보다 우측에 있을 것으로 추정
                left = pivot+1
            else:
                # peak은 pivot 보다 좌측에 있을 것으로 추정
                right = pivot
        # while문은 left == right일 경우 종료되기 때문에 left나 right 둘 중 아무거나 반환 가능
        return right
```



