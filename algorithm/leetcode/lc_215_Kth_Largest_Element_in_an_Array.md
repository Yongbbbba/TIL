# lc 215 Kth Largest Element in an Array

- 퀵정렬 이용해서 짰는데 이 코드는 다 정렬하고 k번째로 큰 수를 뽑아내는거라서 최악의 경우 O(NlogN)일 수 있음. 실행속도가 실제로 빠르지 않았다 -> 이것보다도 이분탐색을 응용하지 못하고, pivot을 고정된 인덱스로 선정하면서 성능이 떨어졌었다.



## 첫 코드

```python
class Solution:
    def quickSort(nums, k):
        if len(nums) == 1 or len(nums) == 0:
            return nums
        pivotIdx = len(nums) - 1
        pivot = nums[pivotIdx]
        leftIdx = 0
        rightIdx = pivotIdx - 1
        
        while leftIdx <= rightIdx:
            if nums[leftIdx] <= pivot:
                leftIdx += 1
                continue
            if nums[rightIdx] > pivot:
                rightIdx -= 1
                continue
            if nums[leftIdx] > pivot and nums[rightIdx] <= pivot:
                nums[leftIdx], nums[rightIdx] = nums[rightIdx], nums[leftIdx]
                continue
        nums[pivotIdx], nums[leftIdx] = nums[leftIdx], nums[pivotIdx]
        leftArr = Solution.quickSort(nums[:leftIdx], k)
        rightArr = Solution.quickSort(nums[leftIdx+1:], k)
        return leftArr + [pivot] + rightArr
        
        
    def findKthLargest(self, nums: List[int], k: int) -> int:
        sortedNums = Solution.quickSort(nums, k)
        return sortedNums[len(sortedNums) - k]
        
```



## 두 번째 코드

- 파이썬에서 재귀돌 때 `self.메소드` 했어야 했는데 self를 빼먹어서 자꾸 NameError가 발생.. 자바나 C++처럼 this를 자꾸 넣어서 안돌아감
- 이번 코드는 약간 이분탐색을 응용해서 풀이한 것인데 속도가 드라마틱하게 빨라지진 않았다. 

```python 
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if len(nums) == 1:
            return nums[0]
        pivotIdx = len(nums) - 1
        pivot = nums[pivotIdx]
        leftIdx = 0
        rightIdx = pivotIdx - 1
        while leftIdx <= rightIdx:
            if nums[leftIdx] <= pivot:
                leftIdx += 1
                continue
            if nums[rightIdx] > pivot:
                rightIdx -= 1
                continue
            if nums[leftIdx] > pivot >= nums[rightIdx]:
                nums[leftIdx], nums[rightIdx] = nums[rightIdx], nums[leftIdx]
                continue
        nums[leftIdx], nums[pivotIdx] = nums[pivotIdx], nums[leftIdx]
        
        if len(nums) - k == leftIdx:
            return pivot
        if len(nums) - k < leftIdx:
            return self.findKthLargest(nums[:leftIdx], k - (len(nums) - leftIdx))
        else:
            return self.findKthLargest(nums[leftIdx+1:], k)
        
```



## 세 번째 코드

- 허무하게도 이게 제일 빠름. 내가 작성한 퀵소트는 pivot설정 문제 때문에 최선의 시간복잡도를 나타내지 못하기 때문이 아닐까싶다.

```python 
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort()
        return nums[len(nums) - k]
        
```



## 네 번째 코드

- 불굴의 의지로 pivot을 랜덤하게 정해서 정렬 + 이분탐색으로 세 번째 코드 방식과 속도 비슷하게 만들었다

```python
`from random import randrange

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if len(nums) == 1:
            return nums[0]
        pivotIdx = randrange(len(nums))
        pivot = nums[pivotIdx]
        nums[pivotIdx], nums[len(nums)-1] = nums[len(nums)-1], nums[pivotIdx]
        leftIdx = 0
        rightIdx = len(nums) - 2
        while leftIdx <= rightIdx:
            if nums[leftIdx] <= pivot:
                leftIdx += 1
                continue
            if nums[rightIdx] > pivot:
                rightIdx -= 1
                continue
            if nums[leftIdx] > pivot >= nums[rightIdx]:
                nums[leftIdx], nums[rightIdx] = nums[rightIdx], nums[leftIdx]
                continue
        nums[leftIdx], nums[len(nums) - 1] = nums[len(nums) - 1], nums[leftIdx]
        
        if len(nums) - k == leftIdx:
            return pivot
        if len(nums) - k < leftIdx:
            return self.findKthLargest(nums[:leftIdx], k - (len(nums) - leftIdx))
        else:
            return self.findKthLargest(nums[leftIdx+1:], k)
```

