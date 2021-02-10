# 4831_전기 버스



T = int(input())

for tc in range(1, T+1):
    # K : 이동할 수 있는 거리
    # N : 마지막 종점의 위치
    # M : 충전소의 개수
    K, N, M = map(int, input().split())

    charge = list(map(int, input().split()))

    bus_stop = [0] * (N+1)

    # 충전소를 표시하기
    for i in charge:
        bus_stop[i] = 1

    bus = 0 # 버스 위치, 시작 위치는 0
    ans = 0 # 충전 횟수

    while True:
        #버스가 이동할 수 있는만큼 이동을 하자.
        bus += K
        if bus >= N : break # 종점에 도착하거나 종점지나 더 나아간 경우

        for i in range(bus,bus-K, -1):
            # 직전 자리로 되돌아가면 도착할 수 없으니 0 반환
            if bus_stop[i]:
                ans += 1
                bus = i
                break
        #충전기를 못찾았을 때
        #else에 걸리면 위에 for문에서 break 되지 않았다는 뜻 
        else:
            ans = 0
            break


    print('#{} {}'.format(tc, ans))


#################다른 방법############################

T = int(input())

for tc in range(1, T+1):
    K,N,M  = map(int, input().split())

    charge = list(map(int, input().split()))

    ans = 0

    # 아래와 같은 코드
    charge = [0] + charge + [N]
    # charge.insert(0,0)
    # cahrge.append(N)

    last = 0 # 지난 번 충전소
    # 충전소에 출발점과 도착지를 넣어놨으므로 len은 M+2
    # 충전소 사이의 거리가 K가 넘는다는 N까지 도착을 못한다는 뜻임
    for i in range(1, M+2):
        if charge[i] - charge[i-1] > K:
            ans = 0
            break
        
        # 갈 수 있으면 아무작업 x
        # 해당 충전소로 갈 수 없다면 내 바로직전 충전소로 위치를 옮기고 횟수 1회 증가
        if charge[i] > last + K:
            last = charge[i-1]
            ans += 1

    print('#{} {}' .format(tc, ans))
