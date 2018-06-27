S = input()
E = int(input())
r = [list(input().split()) for i in range(0,E)]
def f(rr):
    for rrr in rr:
        if (S.endswith(rrr)):
            return True

    return False

r = list(filter(f,r))
EE = int(input())
for i in range(0,EE):
    st = input()
    comp = False
    for rr in r:
        for rrr in rr:
            if (st.endswith(rrr)):
                print("YES")
                comp = True
                break;
        if comp==True :
            break;


    if comp==False :
        print("NO")
    
