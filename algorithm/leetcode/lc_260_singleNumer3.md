# leetcode  260 Single Number 3

- 스스로 풀지 못함
- 이걸 비트 연산으로 한다고.. ?
- 만약 input이 [1,1,2,2,3,4] 일 때 3^4는 적어도 한 비트는 1이다.
- 1인 비트를 기준으로 모든 원소를 두 그룹으로 나눌 수 있음
- 각 그룹마다 유일하게 등장하는 원소는 하나!



## 코드

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        if len(nums) == 2:
            return nums
        
        ret = 0
        
        for num in nums:
            ret ^= num
        
        # 한 번 등장한 숫자를 xor 한 값이 ret에 들어와있게 되는데,
        # 둘은 같은 수가 아니므로 적어도 하나의 비트는 1의 값을 가질 수밖에 없다.
        # 다시 말해서 하나의 수는 그 자리에 0의 값을, 다른 수는 1의 값을 가질 것이다.
        # 다시 순회하면서 해당 자리수가 0인 그룹과 1인 그룹으로 둘로 나눠서 xor을 다시 해주면
        # 각각의 값이 나오게 된다.
        ret1 = 0
        ret2 = 0
        
        for i in range(32):  # 문제에서 32비트라는 제약이 있음
            if (ret >> i) & 1:
                idx = i
                break
        
        for num in nums:
            # 해당 자리의 비트가 1인 경우
            if (num >> idx) & 1:
                ret1 ^= num
            # 해당 자리의 비트가 0인 경우
            else:
                ret2 ^= num
                
        return [ret1, ret2]
```

