# leetcode 724 Find Pivot Index

- 슬라이딩 윈도우 알고리즘 사용하면 시간복잡도를 O(N^2)에서 O(N)으로 최적화 가능

## 내 코드

```c++
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right = 0;
        for (auto& num: nums ) 
            right += num;
        int pivot = -1;
        for (int i=0; i<nums.size(); i++)
        {
            right -= nums[i];
            if (left == right)
            {
                pivot = i;
                break;
            }
            else
            {
                left += nums[i];
            }
        }
        return pivot;
    }
};
```

