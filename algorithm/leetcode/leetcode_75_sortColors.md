# leetcode sort colors

- 그냥 색깔을 각각 센 후에 이를 이용해 정렬된 배열을 만들고, nums의 값을 바꿔줌(counting sorting)  -> 임시 배열을 사용하기 때문에 추가 스택 공간 필요
- in-place swap로도 구할 수 있음. 임시 배열을 저장하는 스택 메모리 공간이 필요없음



## 계수정렬 코드

```python
class Solution(object):
    def sortColors(self, nums):
        cnt = [0,0,0]
        for num in nums:
            cnt[num] += 1

        arr = []
        for idx in range(3):
            arr += [idx] * cnt[idx]
        for idx in range(len(nums)):
            nums[idx] = arr[idx]
```



## in-place swap 코드

```python
class Solution(object):
    def sortColors(self, nums):
        check = 0
        present_left = 0
        present_right = len(nums)-1
        # present_left 좌측으로는 0만 있을 것이고
        # present_right 우측으로는 2만 있을 것이다
        while check <= present_right:
            if nums[check] == 0:
                nums[check], nums[present_left] = nums[present_left], nums[check]
                present_left += 1
                check+=1
            elif nums[check] == 2:
                nums[check], nums[present_right] = nums[present_right], nums[check]
                present_right -= 1
                # 여기서 check++를 하지 않는 이유는, present_right에 있는 숫자가 무슨 숫자가 있었는지는 모르기 때문에 0,1,2 중 어떤 것인지 체크해야하기 때문이다.
            else:
                check += 1
```

