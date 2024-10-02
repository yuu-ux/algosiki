X = 10

counter = [0] * (X + 1)

dict = {}

def rec(n):
    counter[n] += 1
    if n in dict:
        pass
    elif n in [1, 2]:
        dict[n] = 1
    else:
        dict[n] = rec(n-2) + rec(n-1)
    return dict[n]

rec(10)
for index in range(1, X+1):
    print(counter[index])


