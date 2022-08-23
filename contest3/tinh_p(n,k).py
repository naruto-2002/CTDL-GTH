mod = 1000000007
t = int(input())
while(t):
    n, k = map(int, input().split(' '))
    res = 1;
    if(k > n): print(0)
    else: 
        for i in range(0, k):
                res %= mod
                res *= (n-i)%mod
                res %= mod
        print(res)
    t -= 1