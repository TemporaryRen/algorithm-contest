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



t = II()
t = 1
for _ in range(t):
    n,q = MII()
    a = LII()
    ss = set()
    for i in range(q):
        l,r = MII()
        l -= 1
        r -= 1
        print(a[l:r+1])