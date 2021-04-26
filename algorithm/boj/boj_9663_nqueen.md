# boj 9663 N-Queen

- 백트래킹의 대표 문제
- 2차원 배열을 만들어서 문제를 풀었다. 문제에서 N=15까지 주워져있는데, 시간초과가 났다.



## 코드 : 2차원 배열 사용

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int result = 0 ;
int dr[8] = {1, 1, -1, -1, 0, 1, 0, -1};
int dc[8] = {1, -1, -1, 1, 1, 0, -1, 0};
vector<vector<int>> arr(15, vector<int>(15, 0));


bool checkQueen(int r, int c)
{
    for (int d=0; d<8; d++)
    {
        int cnt = 1;
        while (true)
        {
            int nr = r + dr[d] * cnt;
            int nc = c + dc[d] * cnt;
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) break;
            if (arr[nr][nc] == 0) cnt++;
            else return true;
        }
    }
    return false;  // 현재 칸의 8방향에 퀸이 없음
}

void f(int r)
{
    if (r==N)
    {
      result++;
      return;  
    } 

    for (int j=0; j<N; j++)
    {
        // 현재 칸에 퀸을 놓는게 가능한 위치인지 확인
        if (!checkQueen(r, j))
        {
            arr[r][j] = 1;
            f(r+1);
            arr[r][j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
   cin >> N;

    f(0);

    cout << result;

    return 0;
}
```



## 코드 : 1차원 배열 사용

- 약간의 수학적(?) 개념을 사용해야한다. (isUsed2, isUsed3 부분). j번째 열에는 퀸이 하나만 들어갈 수 있음이 자명하므로 isUsed1에 체크. 
- 같은 우하향 대각선 상에 있다면 x-y의 값이 같음을 이용.
- 같은 우상향 대각선 상에 있다면 x+y의 값이 같음을 이용.

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int result = 0 ;
bool isUsed1[15];  // 열 검사
bool isUsed2[100];  // 우하향 대각선 검사, [x - y + N] 검사(음수 인덱스 방지용으로 N 더해줌)). 같은 우하향 대각선 상에 있다면 x-y의 값이 같음을 이용
bool isUsed3[100];   // 우상향 대각선 검사, [x+y] 검사. 같은 우상향 대각선 상에 있다면 x+y의 값이 같음을 이용

void f(int r)
{
    if (r==N)
    {
      result++;
      return;  
    }

    for (int j=0; j<N; j++)
    {
        if (isUsed1[j] == 0 && isUsed2[r-j+N] == 0 && isUsed3[r+j] == 0)
        {
            isUsed1[j] = 1; isUsed2[r-j+N] = 1; isUsed3[r+j] = 1;
            f(r+1);
            isUsed1[j] = 0; isUsed2[r-j+N] = 0; isUsed3[r+j] = 0;
        }
    }
   
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
   cin >> N;

    f(0);

    cout << result;

    return 0;
}
```

