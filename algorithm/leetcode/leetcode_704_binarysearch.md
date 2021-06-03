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

