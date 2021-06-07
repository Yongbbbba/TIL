# leetcode 56 merge intervals

- O(NlogN)으로 풀이하는 것이 베스트
- 우선 정렬을 한 후에 비교하는 방법 사용



## 코드

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        N = len(intervals)
        intervals.sort(key=lambda x : x[0])  # O(N*logN)
        result = []
        start = intervals[0][0]
        end = intervals[0][1]
        for idx in range(1, N):
            first, second = intervals[idx]
            # 구간이 겹치는 경우
            if first <= end:
                if second < end:
                    continue
                else:
                    end = second
            # 구간이 겹치지 않는 경우
            else:
                result.append([start, end])
                start = first
                end = second
        result.append([start, end])
        
        return result
        
        
```

