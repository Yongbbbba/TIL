# swea _9842_subtree

- 처음 내가 반복문으로 짠 코드가 테스트 케이스를 3개만 통과했다. 그 이유를 몰랐는데, 교수님께서 해주신 설명을 듣고 이해가 갔다. 내 코드의 문제는, 노드의 왼쪽 오른쪽을 모두 확인하는게 아니고 한쪽 방향만 확인하기 때문에 누락되는 노드들이 있었다.
- 트리는 나름 정석적인 방법(재귀를 활용)이 있기 때문에 이를 우선적으로 활용하자.



## 내 코드

```python
T = int(input())

for tc in range(1, T + 1):
    E, N = map(int, input().split())
    ch1 = [0] * (E*2)
    ch2 = [0] * (E*2)
    edge = list(map(int, input().split()))
	
    for i in range(0, len(edge), 2):
        node =edge[i]
        child = edge[i+1]
        
        if ch1[node] == 0:
            ch1[node] = child
        else:
            ch2[node] = child
            
    result = 1
    temp = N

    while ch1[N] != 0:
        result+=1
        N = ch1[N]

    while ch2[temp] != 0:
        result+=1
        temp = ch2[temp]

    print(f'#{tc} {result}')
```



## 재귀를 활용

```python
T = int(input())

def inorder(N):
    global result, E, ch1, ch2
    if 0 < N < E+2:
        inorder(ch1[N])
        result+=1
        inorder(ch2[N])


for tc in range(1, T + 1):
    E, N = map(int, input().split())
    ch1 = [0] * (E * 2)
    ch2 = [0] * (E * 2)
    edge = list(map(int, input().split()))

    for i in range(0, len(edge), 2):
        node = edge[i]
        child = edge[i + 1]

        if ch1[node] == 0:
            ch1[node] = child
        else:
            ch2[node] = child

    result = 0

    inorder(N)

    print(f'#{tc} {result}')
```

