# leetcode 136 SIngle Number

- XOR 이용. 선형의 시간복잡도에 상수의 공간복잡도를 써야해서 XOR을 이용해야하는데 이런게 되는 줄 처음 알았다..
- 자기 자신과 xor을 하면 0이 나오고, 0과 어떤 수를 xor하면 자기 자신이 나오는 성질을 이용한다.
- ret=0을 시작으로 리스트를 모두 순회하며 ret와 xor연산을 하고 나면 쌍이 있는 애들은 모두 0이 될 것이고, 쌍이 없는 하나만 0과 xor연산을 해서 자기 자신이 나오는 성질을 이용한다.

## 코드

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        ret = 0
        
        for num in nums:
            ret ^= num
        
        return ret
```

