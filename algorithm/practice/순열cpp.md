# C++로 순열 만들기 : 재귀

- 네이버 코테에서 순열 만드는 법도 까먹어서 문제 못 푼 한이 맺혀서 구현 연습을 해본다.



## 코드

```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr = {1,2,3,4,5};
int N = 5;
int R = 3;
vector<vector<int>> result;

void perm(int n, int r, int i)
{
    if (i==r)
    {
        vector<int> temp;
        for (int k=0; k<r; k++)
        {
            temp.push_back(arr[k]);
        }
        result.push_back(temp);
        return ;
    }

    for (int j=i; j<n; j++)
    {
        swap(arr[j], arr[i]);
        perm(n, r, i+1);
        swap(arr[j], arr[i]);
    }
}
    

int main()
{
   
    perm(N, R, 0);


    for (auto v : result)
    {
        for (auto num : v)
        {
            cout << num << ' ';
        }
        cout << endl;
    }
   
   
    return 0;
}
```



## next_permutation으로 순열과 조합 구하기

```c++
include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <stack>
#include <queue>

using namespace std;

int result = 0;
int result2 = 0;

int main()
{
	int nums[5] = { 1,2,3,4,5 };
	int a[5] = { 0,0,0,1,1 };
	// 조합 출력 5C3
	cout << "조합 출력" << endl;
	do
	{
		for (int i = 0; i < 5; i++)
		{
			if (a[i] == 0)
			{
				cout << nums[i] << ' ';
			}
		}
		result++;
		cout << endl;
	} while (next_permutation(a, a + 5));

	cout << result << endl;


	cout << endl;
    // 순열 출력 5P3
	cout << "순열 출력" << endl;
	do
	{
		for (int i = 0; i < 3; i++)
		{
			cout << nums[i] << ' ';
		}
		reverse(nums + 3, nums + 5);  // 이 부분이 중요
		result2++;
		cout << endl;
	} while (next_permutation(nums, nums + 5));

	cout << result2 << endl;
	
}
```

