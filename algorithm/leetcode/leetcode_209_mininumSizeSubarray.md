# leetcode 209 Minimum Size Subarray Sum

- 배열의 모든 원소가 양수인 것을 이용해서 투포인터 활용
- 너무 어려움..  슬라이딩 윈도우 알고리즘을 잘 이해하지 못 하고 있다.

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        if (nums.size() == 0 ) return  0;
        
        int result = nums.size();
        int start = 0, end = 0, sum = nums[0];
        bool found = false;
        
        while (end < nums.size() && start <= end)
        {
            // sum이 target보다 작으면 서브배열의 사이즈를 늘려본다
            if (sum < target)
            {
                end++;
                if (end < nums.size()) sum+=nums[end];
            }
            // sum이 target 보다 크거나 같으면 일단 그런 서브배열은 찾은 것
            else if (sum >= target)
            {
                // 가장 작은 사이즈의 서브배열이었는지 확인 
                if (result >= end - start + 1)
                {
                    result = end - start + 1;
                    found = true;
                }
                // 사이즈를 한 번 줄여본다
                if (sum > target)
                {
                    sum -= nums[start++];
                }
                else
                {
                    end++;
                    if (end < nums.size())
                        sum += nums[end];
                }
            }
           
        }
        if (found) return result;
        return 0;
    }
};
```



