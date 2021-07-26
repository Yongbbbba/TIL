# boj 1149 RGB거리

- DP로 풀이
- ~~맞는거 같은데 오답이 계속 나왔다. 마지막 출력 부분을 *min_element(dp[N-1], dp[N-1]+2);에서 아래 코드와 같이 바꿨는데 통과가 됐다. g++과 msvc에 뭔가 차이가 있었던걸까..~~
- 바보 같은 실수를 했다. *min_element(dp[N-1], dp[N-1]+3); 이라고 했어야 했는데 *min_element(dp[N-1], dp[N-1]+2);라고 해서 틀린거였다... 



## 코드

```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <stack>
#include <queue>
#include <array>
#include <fstream>

#define ll long long

using namespace std;

int N;

int rgb[1000][3];
int dp[1000][3];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> rgb[i][j];
    }

    // 첫 번째 집 칠하기
    dp[0][0] = rgb[0][0];
    dp[0][1] = rgb[0][1];
    dp[0][2] = rgb[0][2];

    // i번째 집에 j색을 칠하는 최소 비용의 합은 i-1번째 집까지 중 j색이 아니면서 비용이 가장 작은 경우를 택하면 됨
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
            else if (j == 1)
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
            else
                dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
        }
    }
    int result = dp[N - 1][0];
    for (int i = 1; i < 3; i++)
    {
        if (result > dp[N - 1][i])
            result = dp[N - 1][i];
    }
    cout << result;
}
```

