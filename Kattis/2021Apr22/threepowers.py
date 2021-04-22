while(True):
    n=int(input())
    if(n==0): break;
    n-=1;
    result = []
    for i in range(100):
        if(n&(1<<i)):
            result.append(3**i)
    if(result):
        print("{ "+(", ".join(map(str, result)))+" }");
    else:
        print("{ }");
    

