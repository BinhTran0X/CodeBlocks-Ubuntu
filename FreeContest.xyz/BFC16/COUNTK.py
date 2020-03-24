t = int(input())
k, m, n, mod = map(int, input().split())
n = abs(n)
m = abs(m)
for _ in range(t):
    if k < m + n or (k - m - n) % 2 != 0:
        print(0)
        continue
    t = (k - m - n) // 2
    res = 0
    for i in range(t + 1):
        tmp = 1
        pos = 1
        for j in range(i):
            tmp *= pos + j
        for j in range(i):
            tmp //= j + 1
        pos += i
        for j in range(n + i):
            tmp *= pos + j
        for j in range(n + i):
            tmp //= j + 1
        pos += n + i
        for j in range(t - i):
            tmp *= pos + j
        for j in range(t - i):
            tmp //= j + 1
        pos += t - i
        for j in range(m + t - i):
            tmp *= pos + j
        for j in range(m + t - i):
            tmp //= j + 1
        pos += i + 1
        res = (res + tmp) % mod
    print(res)
