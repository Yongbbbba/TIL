# leetcode 1710 maximum Units On a Truck

- 그리디하게 풀이
- units이 가장 많은 박스부터 넣어본다.



## 코드

```python
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        # 그리디하게 풀어보기, 유닛이 많은 박스부터 넣어보기
        boxes = sorted(boxTypes, key=lambda x: x[1], reverse=True)
        result = 0
        idx = 0
        n = len(boxTypes)
        
        while truckSize > 0 and idx <= n-1:
            amount, units = boxes[idx]
            if amount <= truckSize:
                result += amount * units
                idx+=1
                truckSize -= amount
            else:
                break
        
        if truckSize > 0 and idx <= n-1:
            _ , units = boxes[idx]
            lastAmount = 0
            while True:
                if lastAmount < truckSize:
                    lastAmount += 1
                else:
                    break
            result += lastAmount * units
        
        return result
```

