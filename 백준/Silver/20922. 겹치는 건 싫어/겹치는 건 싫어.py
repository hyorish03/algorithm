from collections import defaultdict

N, K=map(int,input().split())
numbers=list(map(int, input().split()))
subset=defaultdict(int)
start, end = 0, 0
answer = 0
while end < N:
    if subset[numbers[end]] < K:
        subset[numbers[end]] += 1
        end += 1
    else:
        answer = max(answer, end-start)
        subset[numbers[start]] -= 1
        start += 1

answer = max(answer, end-start)
print(answer)