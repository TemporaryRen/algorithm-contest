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

def cal_left(l,x,r):
    t1 = (l + x) * (x - l + 1) // 2
    t2 = (r - x)
    return t1 * t2

def cal_right(l,x,r):
    t1 = (x + r - 1) * (r - x) // 2
    t2 = (x - l + 1)
    return t1 * t2

def cal(l,x,r):
    return cal_left(l,x,r) + cal_right(l,x,r)

t = 1
#t = II()
for _ in range(t):
    n = II()
    a = LII()
    b = []
    b.append(0)
    for x in a:
        b.append(x.bit_length()-1)
    b.append(1000)
    ans = 0
    hps = []
    for r in range(1,len(b)):
        h = b[r]
        while(len(hps)>0 and b[hps[-1]] <= h):
            x = hps[-1]
            hps.pop();
            x_l = 0 if len(hps) == 0 else hps[-1]
            ans += cal(x_l+1,x,r) * b[x]
            assert(ans >= 0)
        
        hps.append(r)
    
    print(ans)