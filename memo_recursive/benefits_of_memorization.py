X = 10

counter = [0] * (X+1)

def rec(n):
    counter[n] += 1
    if n in [1, 2]:
        return 1
    else:
        return rec(n-2) + rec(n-1)

rec(X)
for idx in range(1,X+1):
    print(counter[idx])
