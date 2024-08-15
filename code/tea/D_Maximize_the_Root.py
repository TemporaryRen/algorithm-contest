def I():
    return input()
def II():
    return int(input())
def MII():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
def LFI():
    return list(map(float, input().split()))
def GMI():
    return map(lambda x: int(x) - 1, input().split())
def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))

import math
inf = math.inf

from collections import Counter, defaultdict, deque


t = II()
for _ in range(t):
    n = II()
    v = LII()
    fa = LII()
    g = {}
    ind = [0] * (n+1)
    mmin = [inf] * (n+1)
    for i,fa in enumerate(fa):
        g[i+2] = fa
        ind[fa] += 1
    zero = []
    for i in range(1,n+1):
        if ind[i] == 0:
            zero.append(i)
    while len(zero) > 0:
        now = zero.pop()
        if now == 1:
            v[0] += mmin[1]
            break
        if mmin[now] != inf:
            if v[now-1] < mmin[now]:
                v[now-1] = (v[now-1] + mmin[now])//2
            else:
                v[now-1] = mmin[now]
        mmin[g[now]] = min(mmin[g[now]],v[now-1])
        ind[g[now]] -= 1
        if ind[g[now]] == 0:
            zero.append(g[now])
    print(v[0])

        
    
    
                
                
    