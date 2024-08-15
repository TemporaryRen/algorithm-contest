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
    s = I()
    ip = 0
    for i in range(len(s)-1):
        if s[i] == s[i+1]:
            ip = i + 1
    ans = ''
    if(ip == 0):
        if s[0] == 'a':
            ans = 'b'
        else:
            ans = 'a'
        ans += s
    else:
        ans = s[0:ip]
        if s[ip] == 'a':
            ans += 'b'
        else:
            ans += 'a'
        ans += s[ip:len(s)]
    print(ans)