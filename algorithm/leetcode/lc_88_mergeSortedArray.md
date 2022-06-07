# lc 88 merge sorted array

- 저급하게 짰다고 생각했는데, 다른 제출 보다 100% 속도가 빠르다고 나와있어서 당황함.. 

```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       vector<int> temp(m+n);
        int idx=0;
        int a = 0;
        int b = 0;
        while (a!=m && b!=n)
        {
            if (nums1[a] > nums2[b])
            {
                temp[idx] = nums2[b];
                idx++;
                b++;
            }
            else
            {
                temp[idx] = nums1[a];
                idx++;
                a++;
            }
        }
        if (m == a)
        {
            while (idx != m+n)
            {
                temp[idx] = nums2[b];
                idx++;
                b++;
            }
        }
        else
        {
            while (idx != m+n)
            {
                temp[idx] = nums1[a];
                idx++;
                a++;
            }
        }
        nums1 =  temp;
    }
};
```



## temp array 안쓴 코드

- 이 코드의 속도는 24% 빠른 속도라는데,  왜 이게 위 코드보다 더 느린지 모르겠다. 투포인터 쓴다는 점에서 위 코드랑 원리는 같은 반면 임시 배열도 생성하지 않는데 말이다..

```c++
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int wIdx = m + n - 1;
        int ptr1 = m - 1;
        int ptr2 = n - 1;

        while (ptr1 != -1 && ptr2 != -1)
        {
            if (nums1[ptr1] >= nums2[ptr2])
            {
                nums1[wIdx] = nums1[ptr1];
                wIdx--;
                ptr1--;
            }
            else
            {
                nums1[wIdx] = nums2[ptr2];
                ptr2--;
                wIdx--;
            }
        }
        while (wIdx != -1)
        {
            if (ptr1 == -1)
            {
                nums1[wIdx] = nums2[ptr2];
                ptr2--;
                wIdx--;
            }
            else
            {
                nums1[wIdx] = nums1[ptr1];
                ptr1--;
                wIdx--;
            }
        }
    }

```

- 아.. 제출을 여러 번 해보니까 두 코드가 그냥 속도 비슷하게 나온다. 우연하게 첫 번째 코드 돌렸을 때 서버 퍼포먼스가 좋았나보다.