# leetcode 283 Move Zeroes

- 0을 옮겨라가 문제 제목이지만 0이 아닌 숫자를 앞으로 보내는 것도 방법.
- 현재 채울 차례인 인덱스와 0이 아닌 숫자의 인덱스를 가리키는 두 가지 인덱스 변수를 사용하면 쉽게 풀림



## 코드

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int targetIdx = 0;
        for (int idx=0; idx< nums.size(); idx++)
        {
            if (nums[idx] != 0)
            {
                swap(nums[idx], nums[targetIdx]);
                targetIdx++;
            }
        }
    }
};
```



## 2022/06/05 1년 뒤의 풀이

- 더 코드가 후져짐. 충격적이다. 

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] == 0 && nums[j] != 0)
				{
					swap(nums[i], nums[j]);
				}
			}
		}
		return;

    }
};
```

