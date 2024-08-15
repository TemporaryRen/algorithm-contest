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
for _ in range(t):
    n = II()
    s = I()
    h = [0]
    ans = 0
    for i in range(1,len(s)):
        if s[i] == '(':
            h.append(i)
        elif s[i] == ')':
            ans += i - h.pop()
        else:
            if len(h) > 0:
                ans += i - h.pop()
            else:
                h.append(i)
    print(ans)