import sys
sys.stdin = open("C:/users/hansung/desktop/input.txt", "r")


def f(s, g, v):
    # 중복없이 빠짐없이 탐색하는 dfs...
    # 스택 생성
    stack = []
    # 방문기록표 생성
    visited = [0] * (V+1)
    # push(s) 갈림길 목록에 시작점 추가
    stack.append(s)
    # visited[s] <- 1 방문 예약 표시(중복된 push 방지)
    visited[s] = 1
    while stack:  # 스택이 비어있지 않으면(방문할 곳이 남아있으면) 계속 탐색
        n = stack.pop()  # 방문할 목록에서 마지막에 기록한 노드를 꺼내어 방문
        # 방문한 노드가 목적지  g인지 확인
        if n == g:
            return 1
        # 모든 노드에 대해, 현재 노드에서 방문할 수 있는 곳인지 검토
        for i in range(1, V+1):
            if arr[n][i] == 1 and visited[i] == 0:  # 인접하고 방문하지 않은 노드를 찾으면
                stack.append(i)  # push(i)
                visited[i] = 1

    return 0  # 목적지에 도달하지 못하고, 탐색할 노드가 더이상 없음


T = int(input())
for tc in range(1, T + 1):
    V, E = map(int, input().split())  # V개의 vertex(node), E개의 edge
    arr = [[0] * (V+1) for _ in range(V+1)]
    for _ in range(E):  # 간선 정보 읽기
        n1, n2 = map(int, input().split())  # 한 개의 간선
        arr[n1][n2] = 1  # n1에서  n2로 이어짐, 일방향이면 여기서 끝남
        # arr[n2][n1] = 1 # n2에서 n2로 이어짐. 양방향이면 여기까지

    S, G = map(int, input().split())
    print(f'#{tc} {f(S, G, V)}')









