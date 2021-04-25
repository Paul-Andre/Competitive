t=int(input())

mod = 43200000000000

def asdf(aa,bb,cc):
    for (a,b,c) in (
            (aa,bb,cc),
            (aa,cc,bb),
            (bb,aa,cc),
            (bb,cc,aa),
            (cc,aa,bb),
            (cc,bb,aa),
    ):
        x = b-a
        x *= 15709090909091
        x%=mod
        y = a-x
        y%=mod

        if(
            (x+y)%mod==a and
            (12*x+y)%mod==b and
                (720*x+y)%mod==c ):
            return x



for tt in range(1, t+1):
    output = "Case #" + str(tt) +":"
    a,b,c = map(int, input().split())


    d=asdf(a,b,c)

    n = d%(10**9)
    d//=(10**9)
    s=d%60
    d//=60
    m=d%60
    d//=60
    h=d
    print(output, h, m, s, n);
