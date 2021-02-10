# 4835_구간합

T = int(input())

for tc in range(1, T+1):
    # N : 원소의 개수
    # M : 구간의 길이

    N, M = map(int, input().split())
    nums = list(map(int, input().split()))

    # 중복된 연산 피하기 
    # 첫 구간은 구해놓기 
    tmp = 0
    for i in range(M):
        tmp += nums[i]

    max_value= tmp
    min_value = tmp

    for i in range(M, N):
        # 새로운 구간의 합을 아주아주아주 간단하게 구할 수 있음
        tmp = tmp + num[i] - num[i-M]

        if max_value < tmp:
            max_value = tmp
        if min_value > tmp:
            min_value = tmp




    print('#{} {}' .format(tc, max_value-min_value))

