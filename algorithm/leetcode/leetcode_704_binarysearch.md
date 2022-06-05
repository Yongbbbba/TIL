# leetcode 704 binary search

- 기초적인 이진 탐색 문제 



```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int pivot = (left + right) / 2;
            if (nums[pivot] == target)
                return pivot;
            else if (nums[pivot] < target)
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        return -1;
    }
};
```



## 2022/06/05 1년 뒤에 다시 푼 결과

- 기본적인 이진탐색 문제도 헤매는 중

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;  
		int end = nums.size() - 1;
		int mid = (end + start) / 2;
		while (start <= end)
		{
			if (nums[mid] == target)
				return mid;
			if (nums[mid] > target)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}	
			mid = (end + start) / 2;
		}
		return -1;

    }
};
```

