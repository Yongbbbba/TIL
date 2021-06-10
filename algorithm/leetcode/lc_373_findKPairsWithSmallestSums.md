# leetcode 373 Find K Pairs with Smallest Sums

- 분류가 힙으로 되어있는데 일단 그냥 이중 순회하면서 모든 경우의 수 집합 만들기, 그 합으로 정렬을 한 후 최대 k개 만큼의 조합을 만들어서 반환하였다. 시간 초과가 날까 싶었는데 안났다. (애초에 다시 보니까 시간 초과 제한이나 시간복잡도 제한이 없네)
  - 집합만들기 -> O(n^2)
  - 정렬 -> O(nlogn)
  - k개까지의 배열 만들기 -> O(k)
  - 결론: O(n^2) + O(k), 근데 n이 10000 이므로 최대 1억이니 이렇게 풀어도 그렇게 오래 걸리지는 않네



## 코드: 무식하게 이중 순회

```python
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        pairs = []
        for num1 in nums1:
            for num2 in nums2:
                pairs.append([num1, num2])
        
        pairs.sort(key=lambda x: x[0]+x[1])
        
        result = []
        for i in range(k):
            try:
                result.append(pairs[i])
            except:
                break
        return result
```



