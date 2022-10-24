# lc 215 Kth Largest Element in an Array

- 퀵정렬 이용해서 짰는데 이 코드는 다 정렬하고 k번째로 큰 수를 뽑아내는거라서 최악의 경우 O(NlogN)일 수 있음. 실행속도가 실제로 빠르지 않았다
- 리트코드에서 기본으로 제공하는 메소드의 인터페이스 때문에 다 정렬하고 나서 뽑았는데 다르게 풀 수도 있을 것 같다



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



