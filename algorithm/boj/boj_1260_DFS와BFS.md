# boj 1260 DFS와 BFS

- 왜 아직도 DFS와 BFS 기본문제에도 쩔쩔메는 것인가..



## 코드

``` c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <stack>
#include <queue>
#include <array>
#include <fstream>
#include <set>
#include <sstream>
#include <unordered_set>

typedef long long ll;

using namespace std;

int N, M, V;
int vis[10001];
vector<vector<int>> arr(1001, vector<int>());

void dfs(int node)
{
    cout << node << ' ';
    vis[node] = 1;
    for (auto n : arr[node])
    {
        if (vis[n] == 0)
            dfs(n);
    }
}

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto n : arr[cur])
        {
            if (vis[n] == 0)
            {
                vis[n] = 1;
                q.push(n);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        sort(arr[i].begin(), arr[i].end());

    dfs(V);
    cout << '\n';
    fill(vis + 1, vis + N + 1, 0);
    bfs(V);

    return 0;
}
```

