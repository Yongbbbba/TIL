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

